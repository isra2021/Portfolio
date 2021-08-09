const {Router} = require('express')
const router = Router()

const {renderSignUpForm, renderSigninForm, signin, signup, logout} = require('../controllers/users.controller')

//Log in
router.get('/users/signin', renderSigninForm)

router.post('/users/signin', signin)

//Log out
router.get('/users/signup', renderSignUpForm)

router.post('/users/signup', signup)

router.get('/users/logout', logout)


module.exports = router