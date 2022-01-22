const express = require('express');
const https = require('https');

// const nodemailer = require('nodemailer');

const app = express();

app.get('/',(req,res) =>{
    res.send("Hello world");
});

const port = process.env.PORT || 5000;

app.listen(port, () => {
    console.log(`Server running at port ${port}`);
    https.get('https://codeforces.com/api/contest.ratingChanges?contestId=1627', (resp) => {
    let data = '';

    // A chunk of data has been received.
    resp.on('data', (chunk) => {
        data += chunk;
    });

    // The whole response has been received. Print out the result.
    resp.on('end', () => {
        console.log(JSON.parse(data).status);

        if (JSON.parse(data).result !==undefined)
        {
            console.log(JSON.parse(data).result);
        }
    });

    }).on("error", (err) => {
    console.log("Error: " + err.message);
    });
});

// callAPI()

// sendEmail()