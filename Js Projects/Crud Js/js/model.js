class Model {
    constructor() {
        this.view = null
        this.todos = JSON.parse(localStorage.getItem('todos'))
        if (!this.todos || this.todos.length < 1) {
            this.todos = [
                {
                    id: 0,
                    title: 'Learn JS',
                    description: 'Watch Js Tutorials',
                    completed: false
                }
            ]
            this.currentId = 1
        }
        else {
            this.currentId = this.todos[this.todos.length - 1].id + 1
        }
    }

    save() {
        localStorage.setItem('todos', JSON.stringify(this.todos))
    }

    setView(view) {
        this.view = view
    }

    getTodos() {
        return this.todos
    }

    findTodo(id) {
        return this.todos.findIndex((todo) => todo.id === id)
    }

    toggleCompleted(id) {
        const index = this.findTodo(id)
        const todo = this.todos[index]
        todo.completed = !todo.completed
        this.save()
    }

    editTodo(id, values) {
        const index = this.findTodo(id)
        Object.assign(this.todos[index], values)
        this.save()
    }

    addTodo(title, description) {
        const todo = {
            id: this.currentId++,
            title,
            description,
            completed: false
        }
        this.todos.push(todo)
        this.save()
        return { ...todo }
        /*Devolvemos un clon ya que si retornamos todos voy a estar
        retornando la referencia y podria hacerle cambios desde la view
        para evitar esto podemos usar Objet.assign({}, todo)
        o mas bien return {...todo}*/
    }

    removeTodo(id) {
        const index = this.findTodo(id)
        this.todos.splice(index, 1)
        this.save()
    }
}
export default Model