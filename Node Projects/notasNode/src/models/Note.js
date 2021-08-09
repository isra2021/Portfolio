/*Con Schema y model voy a definir lo que guardo en mi base de datos*/
const {Schema, model} = require('mongoose');
 
//Esquema
const NoteSchema = new Schema({
   title: {type: String, required: true},
   description: {type: String, required: true},
},
{
   /*Cuando se cree un modelo de esta clase se le va a
   añadir automáticamente una fecha de creación y de actualización*/
   timestamps: true
});
 
 
/*Creamos el modelo Note y lo dejamos listo para exportar*/
module.exports = model('Note', NoteSchema);