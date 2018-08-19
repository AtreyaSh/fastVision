source("optimizeDPI.R", encoding = "UTF-8")
dpi <- optimizeDPI("./dataC/test.pdf", "./results/results.csv")
write.csv(dpi, "./results/dpi.csv", row.names = FALSE)