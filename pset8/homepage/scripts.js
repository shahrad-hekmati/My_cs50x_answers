// scripts.js

// Set background color for mission pages
document.addEventListener("DOMContentLoaded", function () {
    const missionPages = ["mission1.html", "mission2.html", "mission3.html", "mission4.html"];

    if (missionPages.includes(window.location.pathname)) {
        const missionColor = "#0B3D91"; // Mission Color

        document.body.style.backgroundColor = missionColor;
    }
});
