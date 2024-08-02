function hacked() {
    alert('hacked');
}

window.addEventListener('load', function () {
    var form = document.querySelector("form");
    if (form) {
        form.addEventListener('submit', function (event) {
            var inputs = form.querySelectorAll("input[type='text'], input[type='number']");
            var filled = Array.from(inputs).some(input => input.value.trim() !== "");

            if (filled) {
                hacked();
            }
            event.preventDefault();
        });
    }
});
