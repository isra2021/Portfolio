# encoding: utf-8
# Revisión 2019 (a Python 3 y base64): Pablo Ventura
# Copyright 2014 Carlos Bederián
# $Id: connection.py 455 2011-05-01 00:32:09Z carlos $

import socket
import os
from constants import *
from base64 import b64encode
import sys


class Connection(object):
    """
    Conexión punto a punto entre el servidor y un cliente.
    Se encarga de satisfacer los pedidos del cliente hasta
    que termina la conexión.
    """

    def __init__(self, socket, directory):
        self.socket = socket
        self.directory = os.getcwd() + '/' + directory + '/'
        self.connected = True

    def get_file_listing(self):
        try:
            files = os.listdir(self.directory)
            return R_OK + (EOL).join(files) + EOL + EOL
        except FileNotFoundError:
            return R_INTERNAL_ERROR

    def get_metadata(self, filename):
        try:
            file_size = os.path.getsize(self.directory + filename)
            return R_OK + str(file_size) + EOL
        except:
            return R_FILE_NOT_FOUND

    def get_slice(self, filename, offset, size):
        try:
            file = open(self.directory + filename, "rb")
            file.seek(offset)
            string = file.read(size)
            chunk = b64encode(string)
            file.close()
            return R_OK + chunk.decode("ascii") + EOL
        except:
            return R_INTERNAL_ERROR

    def quit(self):
        self.connected = False
        self.socket.close()

    def handle(self):
        buff = ""
        while self.connected:
            try:
                request = self.socket.recv(2048).decode("ascii")
                if not request:
                    break
            except:
                self.quit()
                break

            request = buff + request
            cmds = request.split(EOL)
            buff = cmds.pop(-1)

            for cmd in cmds:
                args = cmd.split()
                if not args:
                    break
                if '\n' in cmd:
                    self.socket.send(R_BAD_EOL.encode("ascii"))
                    self.quit()
                    break
                if args[0] == "get_file_listing":
                    if len(args) == 1:
                        response = self.get_file_listing()
                        self.socket.send(response.encode("ascii"))
                        if response == R_INTERNAL_ERROR:
                            self.quit()
                            break
                    else:
                        self.socket.send(R_INVALID_ARGUMENTS.encode("ascii"))
                elif args[0] == "get_metadata":
                    if len(args) == 2:
                        self.socket.send(self.get_metadata(
                            args[1]).encode('ascii'))
                    else:
                        self.socket.send(R_INVALID_ARGUMENTS.encode("ascii"))
                elif args[0] == "get_slice":
                    if len(args) == 4 and args[2].isdigit() and args[3].isdigit():
                        filename = args[1]
                        offset = int(args[2])
                        size = int(args[3])
                        try:
                            filesize = os.path.getsize(
                                self.directory + filename)
                            if offset >= filesize:
                                self.socket.send(R_BAD_OFFSET.encode("ascii"))
                            elif offset < 0 or size < 0:
                                self.socket.send(
                                    R_INVALID_ARGUMENTS.encode("ascii"))
                            else:
                                response = self.get_slice(
                                    filename, offset, size)
                                self.socket.send(response.encode("ascii"))
                                if response == R_INTERNAL_ERROR:
                                    self.quit()
                                    break
                        except:
                            self.socket.send(R_FILE_NOT_FOUND.encode("ascii"))
                    else:
                        self.socket.send(R_INVALID_ARGUMENTS.encode("ascii"))
                elif args[0] == "quit":
                    if len(args) == 1:
                        self.socket.send(R_OK.encode("ascii"))
                        self.quit()
                        break
                    else:
                        self.socket.send(R_INVALID_ARGUMENTS.encode("ascii"))
                else:
                    self.socket.send(R_INVALID_COMMAND.encode("ascii"))
