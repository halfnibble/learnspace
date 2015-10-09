// Compiled by ClojureScript 0.0-2505
goog.provide('test.core');
goog.require('cljs.core');
test.core.handle_click = (function handle_click(){
return alert("Hello!");
});
test.core.clickable = document.getElementById("clickable");
test.core.clickable.addEventListener("click",test.core.handle_click);
