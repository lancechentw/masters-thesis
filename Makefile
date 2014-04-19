THESIS=		thesis
XELATEX=	xelatex
BIBER=		biber

all: $(THESIS).pdf

$(THESIS).pdf:
	$(XELATEX) $(THESIS)
	$(BIBER)   $(THESIS)
	$(XELATEX) $(THESIS)
	$(XELATEX) $(THESIS)

clean:
	rm -f *.aux *.dvi *.bbl *.bcf *.blg *.log *.out *.toc *.lof *.lol *.lot *.snm *.nav *.pdf

# vim: ts=8 sw=8 sts=8 noet
