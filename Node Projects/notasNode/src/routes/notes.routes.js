const {Router} = require('express')
const router = Router()

const {renderNoteForm, createNewNote, renderNotes, renderEditForm, editNote, deleteNote} = require('../controllers/notes.controller')

router.get('/notes/add', renderNoteForm)//get: obtiene algo del servidor

router.post('/notes/new-note', createNewNote)//post: el servidor recibe los datos del usuario

router.get('/notes', renderNotes)

//edit
router.get('/notes/edit/:id', renderEditForm)


router.put('/notes/edit/:id', editNote)

router.delete('/notes/delete/:id', deleteNote)


module.exports = router