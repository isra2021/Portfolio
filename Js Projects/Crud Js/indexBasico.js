document.addEventListener('DOMContentLoaded', () => {
    const title = document.getElementById('title')
    const description = document.getElementById('description')
    const alert = document.getElementById('alert')
    const btnAdd = document.getElementById('add')
    const table = document.getElementById('table')

    let id = 1

    const addTodo = () => {
        if (title.value === '' || description.value === '') {
            alert.classList.remove('d-none')
            alert.innerText = 'Title and description are required'
            return
        }
        alert.classList.add('d-none')

        const row = table.insertRow()

        row.setAttribute('id', id++)

        row.innerHTML = `
            <td>${title.value}</td>
            <td>${description.value}</td>
            <td class="text-center">
                <input type="checkbox">
            </td>
            <td class="text-right">
                <button class="btn btn-primary mb-1">
                    <i class="fa fa-pencil"></i>
                </button>
            </td>
        `
        const btnRemove = document.createElement('button')
        btnRemove.classList.add('btn', 'btn-danger', 'mb-1', 'ml-1')
        btnRemove.innerHTML = '<i class="fa fa-trash"></i>'
        btnRemove.onclick = () => {
            document.getElementById(row.getAttribute('id')).remove()
            //removeRow(row.getAttribute('id'))
        }
        row.children[3].appendChild(btnRemove)
    }


    const removeRow = (id) => {
        document.getElementById(id).remove()
    }

    btnAdd.onclick = addTodo


})