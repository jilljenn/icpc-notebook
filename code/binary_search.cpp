// dernier 0 de predicat[l..r[ en supposant croissance
if (predicat(l))
	return l - 1;
while (r - l > 1) {
	int m = (l + r) / 2;
	if (predicat(m))
		r = m;
	else
		l = m;
}
return l;
