all: airplane.pdf

watch: airplane.tex
	echo latexmk -pvc -view=pdf $< 

%.pdf: %.tex Makefile
	latexmk -pdf -pdflatex="pdflatex -interactivenonstopmode" -use-make $<

clean: 
	latexmk -CA
	rm -rf \#* *~
