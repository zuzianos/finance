#include "XmlHendler.h"
#include "Markup.h"

string XmlHendler::getFileName()
    {
        return FILE_NAME;
    }


bool XmlHendler::IsFileEmpty(){

    CMarkup xml;
    bool fileExist=xml.Load(getFileName());
    //bool wellFormed = xml.IsWellFormed(getFileName());

    if (fileExist=true)
    return true;

    else
    return false;
}
