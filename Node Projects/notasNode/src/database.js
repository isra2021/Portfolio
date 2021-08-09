const mongoose = require('mongoose')

const {NOTES_APP_MONGODB_DATABASE,NOTES_APP_MONGODB_PASS,NOTES_APP_MONGODB_USER} = process.env

const connect = `mongodb+srv://israel:jinxadc2021@cluster0.xmjcs.mongodb.net/bd_notas?retryWrites=true&w=majority`

mongoose.connect(connect, {
    useNewUrlParser:true,
    useUnifiedTopology:true,
    useFindAndModify: false,
    useCreateIndex: true
})
.then(db =>
    console.log('Base de datos conectada'))
    .catch(err => console.log(err))