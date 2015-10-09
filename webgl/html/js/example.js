var canvas = document.getElementById('canvas'),
	context = canvas.getContext('2d'),
	string = "Hello Canvas";

context.font = '38pt Arial';
context.fillStyle = 'cornflowerblue';
context.strokeStyle = 'blue';

context.fillText(string, canvas.width/2 - 150, canvas.height/2 + 15);
context.strokeText(string, canvas.width/2 - 150, canvas.height/2 + 15);

var testURL = canvas.toDataURL('image/png');
var testIMG = document.getElementById('testIMG');
testIMG.src = testURL;

var testLINK = document.getElementById('testLINK');
testLINK.href = testURL;