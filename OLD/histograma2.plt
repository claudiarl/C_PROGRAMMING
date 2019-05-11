f(x)=(1**x)/(2**(2+x))
plot  "histograma3.dat" using 1:3 title "L=64 y r=1" with linespoints,\
"histograma4.dat" using 1:3 title "L=1024 y r=1" with linespoints,\
f(x) title "Distribución teórica" with lines
set xlabel "Longitud de hueco"
set xrange [1:21]
set ylabel "Frecuencia"
set yrange [0:0.15]
set terminal png
set output "histograma_1.png"
replot
