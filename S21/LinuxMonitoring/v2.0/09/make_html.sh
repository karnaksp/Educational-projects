source ./names.sh

rm -rf ./$metrics
rm -rf ./$head
rm -rf /data/www/index.html
rm -rf /data/www/metrics/index.html

echo "<html>
			<head><title>My Exporter</title></head>
			<body>
			<h1>My Exporter</h1>
			<p><a href="/metrics">Metrics</a></p>
			</body>
			</html>" > $head

cp ./$head /data/www/index.html
