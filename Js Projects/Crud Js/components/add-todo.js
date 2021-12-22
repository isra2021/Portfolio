import Alert from "./alert.js"

class AddTodo {

    constructor() {
        this.btn = document.getElementById('add')
        this.title = document.getElementById('title')
        this.description = document.getElementById('description')
        this.alert = new Alert('alert')
    }

    onClick(callback) {
        this.btn.onclick = () => {
            if (this.title.value === '' || this.description.value === '') {
                this.alert.show('Title and Description are required')
            }
            else {
                this.alert.hide()
                callback(this.title.value, this.description.value)
            }
        }
    }
}
export default AddTodo