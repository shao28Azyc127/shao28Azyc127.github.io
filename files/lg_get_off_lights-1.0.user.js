// ==UserScript==
// @name         lg_get_off_lights
// @namespace    http://example.com/
// @version      1.0
// @description  洛谷取出灯泡（lg已经修了这个bug了）
// @author       shao28Azyc139|700972
// @match        https://*.luogu.com.cn/*
// @match        https://*.luogu.com/*
// @icon         https://www.luogu.com.cn/favicon.ico
// @grant        none
// ==/UserScript==
(function() {
    'use strict';
    if(window.location.pathname.includes("/team")){var a=window.location.pathname.slice(6,100);}
    var light="https://www.luogu.com.cn/api/team/exit/"+a;
    document.getElementsByClassName("user-nav")[0].firstChild.innerHTML+='<button class="test">Got off lights</button>';
    document.getElementsByClassName("user-nav")[0].firstChild.lastChild.onclick=function(){
        fetch(light, {
  "headers": {
    "accept": "application/json, text/plain, */*",
    "x-csrf-token":document.querySelector("meta[name=csrf-token]").content
  },
  "body": null,
  "method": "POST"
});};
})();