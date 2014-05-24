THESIS=		thesis
XELATEX=	xelatex
TEX_OPTIONS=	-shell-escape
BIBER=		biber

all: svg $(THESIS).pdf

$(THESIS).pdf:
	$(XELATEX) $(TEX_OPTIONS) $(THESIS)
	$(BIBER)   $(THESIS)
	$(XELATEX) $(TEX_OPTIONS) $(THESIS)
	$(XELATEX) $(TEX_OPTIONS) $(THESIS)

svg:
	$(MAKE) -C img

clean:
	$(MAKE) -C img clean
	rm -f *.aux *.dvi *.bbl *.bcf *.blg *.log *.out *.toc *.lof *.lol *.lot *.snm *.nav *.pdf

# vim: ts=8 sw=8 sts=8 noet
