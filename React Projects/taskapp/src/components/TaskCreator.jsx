import React, { useState } from 'react'

const TaskCreator = (props) => {

    const [newTaskName, setNewTaskName] = useState('')

    const updateNewTaskValue = (e) => setNewTaskName(e.target.value)

    const createNewTask = () => {
        props.callback(newTaskName) 
    }

    return(
        <div>
            {newTaskName}
            <input
                type="text"
                className="form-control"
                value={newTaskName} 
                onChange={updateNewTaskValue}
            />
            <input
                type="submit"
                className="btn btn-primary mt-1"
                onClick={createNewTask}
                value="Add"
            />
        </div>
    )
}

export default TaskCreator