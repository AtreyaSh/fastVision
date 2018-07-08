#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
// need to be installed beforehand

int main()
{
    char *outText;

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }

    // Open input image with leptonica library, no path needed as image is in base directory
    // Here we can also explore converting pdfs to images
    Pix *image = pixRead("test.png");
    api->SetImage(image);
    // Get OCR result
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText);

    // Destroy used object and release memory
    api->End();
    delete [] outText;
    pixDestroy(&image);

    return 0;
}
