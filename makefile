compile:
	gcc ppmDriver.c ppmUtil.c -Wall -o driver.out

run:
	./driver.out output.ppm

clean:
	rm *.out
	clear
