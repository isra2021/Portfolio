Nombre y apellido: Israel Adrian Angulo.
Compilar: make o make run_main(Memcheck).
Borrar ejecutables y .o : make clean (Solo borra set.o y set)
Ejecutar: ./set

Cosas a tener en cuenta: Si vas a compilar en x86 o mac hay que modificar el makefile poniendo
$(TARGET) : test_set.c set.o list-TuArquitectura.o 