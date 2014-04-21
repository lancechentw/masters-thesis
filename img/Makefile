SVG_FILES=$(notdir $(wildcard src/*.svg))
PDF_FILES=$(SVG_FILES:.svg=.pdf)

all: $(PDF_FILES)

%.pdf: src/%.svg
	inkscape -z -f $< -A $@

clean:
	rm -f *.pdf

# vim: ts=8 sw=8 sts=8 noet
