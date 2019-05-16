f(x)=(4**x)/(5**(2+x))
plot  "histograma5.dat" using 1:3 title "L=64 y r=4" with linespoints,\
"histograma6.dat" using 1:3 title "L=1024 y r=4" with linespoints,\
f(x) title "Distribución teórica" with lines
set xlabel "Longitud de hueco"
set xrange [1:50]
set ylabel "Frecuencia"
set yrange [0:0.04]
set terminal png
set output "histograma_4.png"
replot
