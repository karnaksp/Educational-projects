from flask import (
    Flask,
    request,
    render_template,
    redirect,
    url_for,
    flash,
    send_from_directory,
)
import os
from werkzeug.utils import secure_filename
from mimetypes import guess_type

app = Flask(__name__)
app.config["UPLOAD_FOLDER"] = "static/uploads"
app.config["ALLOWED_EXTENSIONS"] = {"mp3", "wav", "ogg"}
app.secret_key = "secret_key"

os.makedirs(app.config["UPLOAD_FOLDER"], exist_ok=True)


def allowed_file(filename):
    return (
        "." in filename
        and filename.rsplit(".", 1)[1].lower() in app.config["ALLOWED_EXTENSIONS"]
    )


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        if "file" not in request.files:
            flash("No file part")
            return redirect(request.url)
        file = request.files["file"]
        if file.filename == "":
            flash("No selected file")
            return redirect(request.url)
        if file and allowed_file(file.filename):
            filename = secure_filename(file.filename)
            file.save(os.path.join(app.config["UPLOAD_FOLDER"], filename))
            flash("File successfully uploaded")
            return redirect(url_for("index"))
        else:
            flash("Non-audio file detected")
            return redirect(request.url)

    files = os.listdir(app.config["UPLOAD_FOLDER"])
    files_info = [{"name": file, "mime_type": guess_type(file)[0]} for file in files]
    return render_template("index.html", files=files_info)


@app.route("/uploads/<filename>")
def uploaded_file(filename):
    return send_from_directory(app.config["UPLOAD_FOLDER"], filename)


if __name__ == "__main__":
    app.run(port=8888, debug=True)
