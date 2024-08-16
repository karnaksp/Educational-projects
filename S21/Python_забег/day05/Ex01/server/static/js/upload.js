$(document).ready(function() {
    $('#uploadForm').on('submit', function(e) {
        var fileInput = $('#fileInput')[0];
        var file = fileInput.files[0];
        if (file) {
            var fileType = file.type;
            var allowedTypes = ['audio/mpeg', 'audio/wav', 'audio/ogg'];
            if (!allowedTypes.includes(fileType)) {
                e.preventDefault();
                $('#errorAlert').show().delay(3000).fadeOut();
            }
        }
    });
});
