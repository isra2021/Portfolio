const User = require('../models/User')
const passport = require('passport')
const usersCtrl = {}

usersCtrl.renderSigninForm = (req, res) => {
    res.render('./users/signin')
}

usersCtrl.signin = passport.authenticate('local', {
    failureRedirect: '/user/signin',
    successRedirect: '/notes',
    failureFlash: true
})

usersCtrl.renderSignUpForm = (req, res) => {
    res.render('./users/signup')
}

usersCtrl.logout = (req, res) => {
    req.logout();
    req.flash("success_msg", "You are logged out now.");
    res.redirect("/users/signin");
}

usersCtrl.signup = async (req, res) => {
    const errors = [];
    const { name, email, password, confirm_password } = req.body;
    if (password != confirm_password) {
        errors.push({ text: "Passwords do not match." });
    }
    if (password.length < 4) {
        errors.push({ text: "Passwords must be at least 4 characters." });
    }
    if (errors.length > 0) {
        res.render("users/signup", {
            errors,
            name,
            email,
            password,
            confirm_password,
        });
    }
    else {
        // Look for email coincidence
        const emailUser = await User.findOne({ email: email });
        if (emailUser) {
            req.flash("error_msg", "The Email is already in use.");
            res.redirect("/users/signup");
        }
        else {
            // Saving a New User
            console.log(req.body)
            const newUser = new User({ name, email, password });
            newUser.password = await newUser.encryptPassword(password);
            await newUser.save();
            req.flash("success_msg", "You are registered.");
            res.redirect("/users/signin");
        }
    }
}

module.exports = usersCtrl;