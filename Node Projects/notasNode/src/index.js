const { render } = require('./server');
const app = require('./server')
require('./database')
require('dotenv').config();
 
app.listen(app.get('port'), () => {
   console.log(`Server on http://localhost:${app.get('port')}`)
});


