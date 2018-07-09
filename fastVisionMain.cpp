// packages that need to be installed beforehand, must be called again during compilation
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

int main()
{
    char *outText;

    // create new tesseract api object
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();

    // open input image with leptonica library, no path needed as image is in base directory
    // here we can also explore converting pdfs to images
    Pix *image = pixRead("test.png");

    // initialize tesseract-ocr with English
    api->Init(NULL, "eng");
    api->SetImage(image);
    // specify bounding rectangle to reduce search space
    // format (top left x coord, top left y coord, width, height)
    api->SetRectangle(50, 28, 525, 120);

    // get OCR result
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText);

    // destroy used object and release memory
    api->End();
    delete [] outText;
    pixDestroy(&image);

    return 0;
}
