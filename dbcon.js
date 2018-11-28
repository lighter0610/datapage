var mysql = require('mysql');
var connection = mysql.createConnection({
    host: 'localhost',
    user: 'admin',
    password: 'admin',
    database: 'info'
})

connection.connect(function (err) {
    if (err){
        console.log('[quary] - ' + err);
        return;
    }
    console.log('[connection connect] succeed!');
});

function select(sel) {
    connection.query(sel, function (err, result) {
        if (err) {
            console.log('[select error] - ', err.message);
        }
        return result;
    })
}

function insert(ins) {
    connection.query(ins, function (err, result) {
        if (err){
            console.log('[insert error] - ', err.message);
            return;
        }
        return result;
    })
}

function update(upd) {
        connection.query(upd, function (err, result) {
            if (err){
                console.log('[update error] - ', err.message);
                return;
            }
            return result;
        })
}