/^\${PLIST\./ {
	match($0, /^(\${PLIST\.[^}]+})+/);
	c=substr($0, 1, RLENGTH);
	s=substr($0, RLENGTH+1);
	gsub(/\//, "\\/", s);
	gsub(/\$/, "$$", c);
	print "gsub(/^" s "$$/,\"" c "&\");";
}
