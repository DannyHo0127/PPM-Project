compile:
	gcc ppmDriver.c ppmUtil.c -Wall -o driver.out

run:
	./driver.out PoohWCommentsNoEncoding.ppm output1.ppm

clean:
	rm *.out
	clear
