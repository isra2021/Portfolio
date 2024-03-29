import AddTodo from "../components/add-todo.js"
import Modal from "../components/modal.js"

class View {
    constructor() {
        this.model = null
        this.table = document.getElementById('table')
        this.addTodoForm = new AddTodo()
        this.modal = new Modal()
        this.addTodoForm.onClick((title, description) => this.addTodo(title, description))
        this.modal.onClick((id, values) => this.editTodo(id, values))
        //Si nosotros usaramos function nos daria un error
        //porque this se referiria a esa funcion y no a la clase
        //usando arrow function se soluciona
    }

    setModel(model) {
        this.model = model
    }

    render() {
        const todos = this.model.getTodos()
        todos.map(todo => this.createRow(todo))
    }

    addTodo(title, description) {
        const todo = this.model.addTodo(title, description)
        this.createRow(todo)
    }

    toggleCompleted(id) {
        this.model.toggleCompleted(id)
    }

    editTodo(id, values) {
        this.model.editTodo(id, values)
        const row = document.getElementById(id)
        row.children[0].innerText = values.title
        row.children[1].innerText = values.description
        row.children[2].children[0].checked = values.completed
    }

    removeTodo(id) {
        this.model.removeTodo(id)//Elimianndo de la db
        document.getElementById(id).remove()//Eliminando de la view
    }

    createRow(todo) {
        const row = this.table.insertRow()
        row.setAttribute('id', todo.id)

        row.innerHTML = `
            <td>${todo.title}</td>
            <td>${todo.description}</td>
            <td class="text-center"></td>
            <td class="text-right"></td>
        `
        const checkbox = document.createElement('input')
        checkbox.type = 'checkbox'
        checkbox.checked = todo.completed
        checkbox.onclick = () => this.toggleCompleted(todo.id)
        row.children[2].appendChild(checkbox)

        const editBtn = document.createElement('button');
        editBtn.classList.add('btn', 'btn-primary', 'mb-1');
        editBtn.innerHTML = '<i class="fa fa-pencil"></i>';
        editBtn.setAttribute('data-toggle', 'modal');
        editBtn.setAttribute('data-target', '#modal');
        editBtn.onclick = () => this.modal.setValues({
            id: todo.id,
            title: row.children[0].innerText,
            description: row.children[1].innerText,
            completed: row.children[2].children[0].checked,
        });
        row.children[3].appendChild(editBtn);

        const btnRemove = document.createElement('button')
        btnRemove.classList.add('btn', 'btn-danger', 'mb-1', 'ml-1')
        btnRemove.innerHTML = '<i class="fa fa-trash"></i>'
        btnRemove.onclick = () => this.removeTodo(todo.id)
        row.children[3].appendChild(btnRemove)
    }

}
export default View