handbook: code/* handbook.tex
	latexmk -shell-escape handbook.tex
	evince handbook.pdf

clean:
	rm -rf _minted-handbook
	latexmk -c
