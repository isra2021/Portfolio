const {Schema, model} = require('mongoose');
//Para encriptar mi contrasenia, uso de hash
const bcryptjs = require('bcryptjs');
 
/*Esta es la forma en la cual se crean clases en mongoose*/
const UserSchema = new Schema({
   name: {type: String, required: true},
   email: {type: String, required: true, unique: true},
   password: {type: String, required: true}
},
{
   /*Cuando se cree un modelo de esta clase se le va a
   añadir automáticamente una fecha de creación y de actualización*/
   timestamps: true
});
 
/*Tenemos un problema, no queremos guardar la contraseña tal cual
Debemos crear un método para encriptar esa contraseña y lo vamos a hacer
usando el módulo bcryptjs el cual me permite crear hash de cifrado*/
 
/*genSalt(10): Me genera un salt, se ejecuta la cantidad de veces que
le especifique. Cuantas más veces se ejecute más seguro va a ser, pero
va a requerir más trabajo parte del servidor.
genSalt es un método asíncrono, por lo que va a demorar un tiempo
considerable en ejecutarse, es por eso que servidor no necesita esperar.
Por lo tanto le puedo indicar al servidor que siga ejecutando código usando
await en la función genSalt, además tenemos que especificar que el método es async.*/
 
/*Forma de crear métodos dentros de una clase en mongoose usando la propiedad methods*/
UserSchema.methods.encryptPassword = async password => { //password es el parametro
   const salt = await bcryptjs.genSalt(10);
   return await bcryptjs.hash(password, salt);
};
 
/*Cuando se cifre va a ser guardada en la base de datos.
Pero qué pasa cuando un usuario quiere loguearse?
Tengo que comparar la contraseña que ingrese el usuario, cifrar
y por último comparar ese cifrado con el cifrado que esta
en la base de datos.
Necesito implementar un método que compare estas dos contraseñas cifradas.
Lo vamos a implementar usando una función de bcryptjs que nos permite
comparar entre dos cifrados, el método se llama bcrypt.compare().
*/
 
UserSchema.methods.matchPassword = async function(password) {
   return await bcryptjs.compare(password, this.password);
};
 
/*Creamos el modelo User y lo dejamos listo para exportar*/
module.exports = model('User', UserSchema);
