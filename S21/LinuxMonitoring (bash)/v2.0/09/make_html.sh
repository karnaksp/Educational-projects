source ./names.sh

rm -rf ./$head

echo "<html>
			<head><title>My Exporter</title></head>
			<body>
			<h1>My Exporter</h1>
			<p><a href="$metrics">Metrics</a></p>
			</body>
			</html>" > $head


