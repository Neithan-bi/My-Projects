// Theme Toggle
const toggleBtn = document.createElement('button');
toggleBtn.className = 'theme-toggle';
toggleBtn.textContent = 'Toggle Theme';
document.body.appendChild(toggleBtn);

toggleBtn.addEventListener('click', () => {
  document.body.classList.toggle('dark');
});

// Countdown Timer
const eventDate = new Date("April 20, 2025 09:00:00").getTime();

function updateCountdown() {
  const now = new Date().getTime();
  const gap = eventDate - now;

  const days = Math.floor(gap / (1000 * 60 * 60 * 24));
  const hours = Math.floor((gap % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
  const minutes = Math.floor((gap % (1000 * 60 * 60)) / (1000 * 60));
  const seconds = Math.floor((gap % (1000 * 60)) / 1000);

  document.getElementById("days").innerText = days < 10 ? "0" + days : days;
  document.getElementById("hours").innerText = hours < 10 ? "0" + hours : hours;
  document.getElementById("minutes").innerText = minutes < 10 ? "0" + minutes : minutes;
  document.getElementById("seconds").innerText = seconds < 10 ? "0" + seconds : seconds;
}

setInterval(updateCountdown, 1000);

// Scroll to Top Button Show/Hide
const backToTop = document.querySelector('.back-to-top');

window.addEventListener('scroll', () => {
  if (window.scrollY > 300) {
    backToTop.classList.add('show');
  } else {
    backToTop.classList.remove('show');
  }
});
