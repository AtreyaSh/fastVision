### load libraries ###

if(!require(pdftools)) install.packages("pdftools")
library(pdftools)

if(!require(magick)) install.packages("magick")
library(magick)

if(!require(png)) install.packages("png")
library(png)

if(!require(tesseract)) install.packages("tesseract")
library(tesseract)

source("./aux/randString.R", encoding = "UTF-8")

optimizeDPI <- function(pdfPath, dimPath, dpiStart = 72, dpiInc = 10){
  
  ### check dependencies ###
  if(!file.exists(pdfPath)){
    stop(paste0(pdfPath, " does not exist"))
  }
  
  if(!file.exists(dimPath)){
    stop(paste0(dimPath, " does not exist"))
  }
  
  if(!is.numeric(dpiStart) | length(dpiStart) > 1){
    stop("dpiStart must be numerical")
  }
  
  if(!is.numeric(dpiInc) | length(dpiInc) > 1){
    stop("dpiInc must be numerical")
  }
  
  ### define variables ###
  check <- FALSE
  dpi = dpiStart
  dimR <- read.csv(dimPath, stringsAsFactors = FALSE)[,c(3,4,1,2)]
  dimTmp <- dimR
  against <- lapply(1:nrow(dimR), function(x) randString(10))
  
  ### iterations ###
  while(check == FALSE){
    pdf_convert(pdfPath, filenames = "./dataR/next.png", dpi = dpi)
    im <- image_read("./dataR/next.png")
    png <- readPNG("./dataR/next.png")
    x <- ncol(png)
    y <- nrow(png)
    dimTmp[,c(1,3)] <- dimR[,c(1,3)]*x
    dimTmp[,c(2,4)] <- dimR[,c(2,4)]*y
    
    string <- lapply(1:nrow(dimR), function(i) paste0(dimTmp[i,][1],"x",dimTmp[i,][2],"+",dimTmp[i,][3],"+",dimTmp[i,][4]))
    new <- lapply(1:length(string), function(i) image_crop(im, geometry = string[[i]]))
    test <- lapply(new, ocr)
    check <- all(do.call("c", lapply(1:length(string), function(i) test[[i]] == against[[i]])))
    
    if(check == FALSE){
      against <- test
      dpi = dpi + 10
      file.remove("./dataR/next.png")
    }
  }
 return(dpi)
}
