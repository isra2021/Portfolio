import React, { useState } from 'react'

const Usuarios = (props) => {

    //Estatos
    const [nombre, setNombre] = useState('')
    const [edad, setEdad] = useState('')
    const [lista, setLista] = useState([])

    //Funciones
    const updateNombre = (e) => setNombre(e.target.value)

    const updateEdad = (e) => setEdad(e.target.value)
    const agregarUsuario = (e) => {
        e.preventDefault()
        const usuario = {
            nombre,
            edad
        }
        setLista(...lista, usuario)
    }

    return (
        <div className="row border">
            <div className="col-5">
                <h2>Listado de usuarios</h2>
                <hr />
                <ul className="list-group">
                    <li className="list-group-item">Datos introducidos
                        <button className="btn btn-sm btn-primary ml-2 float-right">Editar</button>
                        <button className="btn btn-sm btn-primary ml-2 float-right">Borrar</button>
                    </li>

                </ul>

            </div>
            <div className="col-7">
                <h2>Formulario de usuarios</h2>
                <hr />
                <form className="form-group">

                    <input
                        className="form-control mb-2"
                        type="text"
                        placeholder="Nombre"
                        onChange={updateNombre}
                    />

                    <input
                        className="form-control mb-2"
                        type="text"
                        placeholder="Edad"
                        onChange={updateEdad}
                    />
                    <input
                        className="btn btn-info w-100"
                        type="submit"
                        value="Agregar"
                        onClick={agregarUsuario}
                    />
                </form>
            </div>
        </div>
    );
}

export default Usuarios