const express = require('express')
const path = require('path')
const exphbs = require('express-handlebars')

const methodOverride = require('method-override')
const flash = require('connect-flash')
const session = require('express-session')
const passport = require('passport')

//Initialization
const app = express()
require('./config/passport')

//Settings
app.set('port', process.env.PORT || 4000)
app.set('views', path.join(__dirname, 'views'))

/*Motor de plantillas*/
app.engine('hbs', exphbs({
   defaultLayout: 'main',
   layoutsDir: path.join(app.get('views'), 'layouts'),
   partialsDir: path.join(app.get('views'), 'partials'),
   extname: '.hbs'
}));
app.set('view engine', '.hbs')

//Middlewares
//Cuando lleguen datos de un formaulario lo convertimos en un json
app.use(express.urlencoded({extended: false}))
app.use(methodOverride('_method'))
app.use(session({
   secret: 'secret',
   resave: true,
   saveUninitialized: true
}))
app.use(passport.initialize())
app.use(passport.session())
app.use(flash())
 
//Global Variables
app.use((req, res, next) => { //mext para que 
   res.locals.success_msg = req.flash('success_msg')
   res.locals.error_msg = req.flash('error_msg')
   res.locals.error = req.flash('error')
   res.locals.user = req.user || null
   next()
})

 
//Rutas
app.use(require('./routes/index.routes.js'))
app.use(require('./routes/notes.routes.js'))
app.use(require('./routes/users.routes.js'))

 
//Static files
app.use(express.static(path.join(__dirname, 'public')))
 
 
module.exports = app;