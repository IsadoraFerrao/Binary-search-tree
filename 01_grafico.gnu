set   autoscale                        # scale axes automatically
unset log                              # remove any log-scaling
unset label                            # remove any previous labels
set encoding iso_8859_1

set style line 1 lc rgb 'grey30' ps 0 lt 1 lw 2
set style line 2 lc rgb 'grey70' lt 1 lw 2
set style fill solid 1.0 border rgb 'grey30'
set label '*' at 3,0.8 center
set label '*' at 4,0.8 center
set border 3
#set grid xtics
set grid ytics
#set grid mxtics
#set grid mytics
set ytic auto                          # set ytics automatically
#set xtics rotate by 90 right norangelimit
set xtics rotate by -55 offset -1.5,-0.0
set bmargin 8.0
#set lmargin at screen 0.20
#set rmargin at screen 0.85
set xtics font "helvetica, 18"# textcolor rgb "red"
set ytics font "helvetica, 18"
set title font "helvetica, 18"
set ylabel font "helvetica, 18"
set xlabel font "helvetica, 18"
set title "Tempos de Execucao - Arvore Binaria" tc rgb "black"
#set xlabel "Message size (in bytes)" tc rgb "black"
set xlabel " "
set ylabel "Tempo/segundos" tc rgb "black"
hashes = 'KECCAK256 KECCAK512 BLAKE256 SHA256 RIPEMD160 BLAKE512 SHA512 SHA1 MD5'
index(s) = words(substr(hashes, 0, strstrt(hashes, s)-1)) + 1
set linetype 1 lc rgb 'blue'
set linetype 2 lc rgb 'blue'
set linetype 3 lc rgb 'blue'
set linetype 4 lc rgb 'green'
set linetype 5 lc rgb 'green'
set linetype 6 lc rgb 'blue'
set linetype 7 lc rgb 'green'
set linetype 8 lc rgb 'green'
set linetype 9 lc rgb 'green'
set boxwidth 0.65
set terminal postscript eps enhanced color solid
set output '01_Arvore_BST.eps'
unset key
plot "01_Tempos_de_execucao.dat" u 0:2:(index(strcol(1))):xtic(1) w boxes linecolor variable fs pattern 6
