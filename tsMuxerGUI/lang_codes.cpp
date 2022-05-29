#include "lang_codes.h"

QVariant LangCodesModel::QtvLangCode::toVariant(int role) const
{
    switch (role)
    {
    case Qt::DisplayRole:
        return QString("%1 (%2)").arg(code).arg(lang);
    case Qt::UserRole:
        return code;
    default:
        return QVariant();
    }
}

int LangCodesModel::rowCount(const QModelIndex &) const { return ROW_COUNT; }

QVariant LangCodesModel::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole && role != Qt::UserRole)
    {
        return QVariant();
    }
    const auto row = index.row();
    switch (row)
    {
    case UND_ROW_IDX:
    {
        return m_undLang.toVariant(role);
    }
    case COMMON_ROW_IDX:
    {
        return role == Qt::DisplayRole ? QString("--------- %1 ---------").arg(LangCodesModel::tr("common"))
                                       : QVariant();
    }
    case ALL_ROW_IDX:
    {
        return role == Qt::DisplayRole ? QString("--------- %1 ---------").arg(LangCodesModel::tr("all")) : QVariant();
    }
    default:
    {
        if (row > ALL_ROW_IDX)
        {
            return m_fullLangList[row - (ALL_ROW_IDX + 1)].toVariant(role);
        }
        else
        {
            return m_shortLangList[row - (COMMON_ROW_IDX + 1)].toVariant(role);
        }
    }
    }
}

Qt::ItemFlags LangCodesModel::flags(const QModelIndex &index) const
{
    return (index.row() == COMMON_ROW_IDX || index.row() == ALL_ROW_IDX)
               ? Qt::ItemIsEnabled /* make them unselectable */
               : QAbstractListModel::flags(index);
}

void LangCodesModel::onLanguageChanged()
{
    m_shortLangList = getShortLangList();
    m_fullLangList = getFullLangList();
    m_undLang = QtvLangCode{"und", LangCodesModel::tr("Undetermined")};
    const QVector<int> roles{Qt::DisplayRole};
    emit dataChanged(index(0, 0), index(ROW_COUNT - 1, 0), roles);
}

std::array<LangCodesModel::QtvLangCode, 13> LangCodesModel::getShortLangList()
{
    return {QtvLangCode{"zho", LangCodesModel::tr("Chinese")},
            QtvLangCode{"nld", LangCodesModel::tr("Dutch; Flemish")},
            QtvLangCode{"eng", LangCodesModel::tr("English")},
            QtvLangCode{"fin", LangCodesModel::tr("Finnish")},
            QtvLangCode{"fre", LangCodesModel::tr("French")},
            QtvLangCode{"deu", LangCodesModel::tr("German")},
            QtvLangCode{"ita", LangCodesModel::tr("Italian")},
            QtvLangCode{"jpn", LangCodesModel::tr("Japanese")},
            QtvLangCode{"nor", LangCodesModel::tr("Norwegian")},
            QtvLangCode{"por", LangCodesModel::tr("Portuguese")},
            QtvLangCode{"rus", LangCodesModel::tr("Russian")},
            QtvLangCode{"spa", LangCodesModel::tr("Spanish; Castilian")},
            QtvLangCode{"swe", LangCodesModel::tr("Swedish")}};
}

std::array<LangCodesModel::QtvLangCode, 502> LangCodesModel::getFullLangList()
{
    return {QtvLangCode{"ace", LangCodesModel::tr("Acehnese, Achinese")},
            QtvLangCode{"ach", LangCodesModel::tr("Acoli")},
            QtvLangCode{"ada", LangCodesModel::tr("Adangme")},
            QtvLangCode{"ady", LangCodesModel::tr("Adyghe; Adygei")},
            QtvLangCode{"aar", LangCodesModel::tr("Afar")},
            QtvLangCode{"afh", LangCodesModel::tr("Afrihili")},
            QtvLangCode{"afr", LangCodesModel::tr("Afrikaans")},
            QtvLangCode{"afa", LangCodesModel::tr("Afro-Asiatic (Other)")},
            QtvLangCode{"ain", LangCodesModel::tr("Ainu")},
            QtvLangCode{"aka", LangCodesModel::tr("Akan")},
            QtvLangCode{"akk", LangCodesModel::tr("Akkadian")},
            QtvLangCode{"sqi", LangCodesModel::tr("Albanian")},
            QtvLangCode{"ale", LangCodesModel::tr("Aleut")},
            QtvLangCode{"alg", LangCodesModel::tr("Algonquian languages")},
            QtvLangCode{"tut", LangCodesModel::tr("Altaic (Other)")},
            QtvLangCode{"amh", LangCodesModel::tr("Amharic")},
            QtvLangCode{"anp", LangCodesModel::tr("Angika")},
            QtvLangCode{"apa", LangCodesModel::tr("Apache languages")},
            QtvLangCode{"ara", LangCodesModel::tr("Arabic")},
            QtvLangCode{"arg", LangCodesModel::tr("Aragonese")},
            QtvLangCode{"arc", LangCodesModel::tr("Aramaic")},
            QtvLangCode{"arp", LangCodesModel::tr("Arapaho")},
            QtvLangCode{"arn", LangCodesModel::tr("Araucanian")},
            QtvLangCode{"arw", LangCodesModel::tr("Arawak")},
            QtvLangCode{"hye", LangCodesModel::tr("Armenian")},
            QtvLangCode{"rup", LangCodesModel::tr("Aromanian; Arumanian; Macedo-Romanian")},
            QtvLangCode{"art", LangCodesModel::tr("Artificial (Other)")},
            QtvLangCode{"asm", LangCodesModel::tr("Assamese")},
            QtvLangCode{"ast", LangCodesModel::tr("Asturian; Bable")},
            QtvLangCode{"ath", LangCodesModel::tr("Athapascan languages")},
            QtvLangCode{"aus", LangCodesModel::tr("Australian languages")},
            QtvLangCode{"bar", LangCodesModel::tr("Austro-Bavarian")},
            QtvLangCode{"map", LangCodesModel::tr("Austronesian (Other)")},
            QtvLangCode{"ava", LangCodesModel::tr("Avaric")},
            QtvLangCode{"ave", LangCodesModel::tr("Avestan")},
            QtvLangCode{"awa", LangCodesModel::tr("Awadhi")},
            QtvLangCode{"aym", LangCodesModel::tr("Aymara")},
            QtvLangCode{"aze", LangCodesModel::tr("Azerbaijani")},
            QtvLangCode{"ban", LangCodesModel::tr("Balinese")},
            QtvLangCode{"bat", LangCodesModel::tr("Baltic (Other)")},
            QtvLangCode{"bal", LangCodesModel::tr("Baluchi")},
            QtvLangCode{"bam", LangCodesModel::tr("Bambara")},
            QtvLangCode{"bai", LangCodesModel::tr("Bamileke languages")},
            QtvLangCode{"bad", LangCodesModel::tr("Banda")},
            QtvLangCode{"bnt", LangCodesModel::tr("Bantu (Other)")},
            QtvLangCode{"bas", LangCodesModel::tr("Basa")},
            QtvLangCode{"bak", LangCodesModel::tr("Bashkir")},
            QtvLangCode{"eus", LangCodesModel::tr("Basque")},
            QtvLangCode{"btk", LangCodesModel::tr("Batak (Indonesia)")},
            QtvLangCode{"bej", LangCodesModel::tr("Beja")},
            QtvLangCode{"bel", LangCodesModel::tr("Belarusian")},
            QtvLangCode{"bem", LangCodesModel::tr("Bemba")},
            QtvLangCode{"ben", LangCodesModel::tr("Bengali")},
            QtvLangCode{"ber", LangCodesModel::tr("Berber (Other)")},
            QtvLangCode{"bho", LangCodesModel::tr("Bhojpuri")},
            QtvLangCode{"bih", LangCodesModel::tr("Bihari")},
            QtvLangCode{"bik", LangCodesModel::tr("Bikol languages")},
            QtvLangCode{"bin", LangCodesModel::tr("Bini")},
            QtvLangCode{"bis", LangCodesModel::tr("Bislama")},
            QtvLangCode{"byn", LangCodesModel::tr("Blin; Bilin")},
            QtvLangCode{"bos", LangCodesModel::tr("Bosnian")},
            QtvLangCode{"bra", LangCodesModel::tr("Brij Bhasha")},
            QtvLangCode{"bre", LangCodesModel::tr("Breton")},
            QtvLangCode{"bug", LangCodesModel::tr("Buginese")},
            QtvLangCode{"bul", LangCodesModel::tr("Bulgarian")},
            QtvLangCode{"bua", LangCodesModel::tr("Buriat")},
            QtvLangCode{"bur", LangCodesModel::tr("Burmese")},
            QtvLangCode{"mya", LangCodesModel::tr("Burmese")},
            QtvLangCode{"cad", LangCodesModel::tr("Caddo")},
            QtvLangCode{"car", LangCodesModel::tr("Carib")},
            QtvLangCode{"cat", LangCodesModel::tr("Catalan; Valencian")},
            QtvLangCode{"cau", LangCodesModel::tr("Caucasian (Other)")},
            QtvLangCode{"ceb", LangCodesModel::tr("Cebuano")},
            QtvLangCode{"cel", LangCodesModel::tr("Celtic (Other)")},
            QtvLangCode{"cai", LangCodesModel::tr("Central American Indian (Other)")},
            QtvLangCode{"chg", LangCodesModel::tr("Chagatai")},
            QtvLangCode{"cmc", LangCodesModel::tr("Chamic languages")},
            QtvLangCode{"cha", LangCodesModel::tr("Chamorro")},
            QtvLangCode{"che", LangCodesModel::tr("Chechen")},
            QtvLangCode{"chr", LangCodesModel::tr("Cherokee")},
            QtvLangCode{"chy", LangCodesModel::tr("Cheyenne")},
            QtvLangCode{"chb", LangCodesModel::tr("Chibcha")},
            QtvLangCode{"nya", LangCodesModel::tr("Chichewa; Chewa; Nyanja")},
            QtvLangCode{"zho", LangCodesModel::tr("Chinese")},
            QtvLangCode{"chn", LangCodesModel::tr("Chinook jargon")},
            QtvLangCode{"cho", LangCodesModel::tr("Choctaw")},
            QtvLangCode{"chu", LangCodesModel::tr(
                                   "Church Slavonic; Church Slavic; Old Church Slavonic; Old Slavonic; Old Bulgarian")},
            QtvLangCode{"chk", LangCodesModel::tr("Chuukese")},
            QtvLangCode{"chv", LangCodesModel::tr("Chuvash")},
            QtvLangCode{"nwc", LangCodesModel::tr("Classical Newari; Old Newari; Classical Nepal Bhasa")},
            QtvLangCode{"syc", LangCodesModel::tr("Classical Syriac")},
            QtvLangCode{"cop", LangCodesModel::tr("Coptic")},
            QtvLangCode{"cor", LangCodesModel::tr("Cornish")},
            QtvLangCode{"cos", LangCodesModel::tr("Corsican")},
            QtvLangCode{"cre", LangCodesModel::tr("Cree")},
            QtvLangCode{"mus", LangCodesModel::tr("Creek; Muskogean")},
            QtvLangCode{"crp", LangCodesModel::tr("Creoles and Pidgins (Other)")},
            QtvLangCode{"cpe", LangCodesModel::tr("Creoles and Pidgins, English-based (Other)")},
            QtvLangCode{"cpf", LangCodesModel::tr("Creoles and Pidgins, French-based (Other)")},
            QtvLangCode{"cpp", LangCodesModel::tr("Creoles and Pidgins, Portuguese-based (Other)")},
            QtvLangCode{"crh", LangCodesModel::tr("Crimean Tatar (Crimean Turkish)")},
            QtvLangCode{"hrv", LangCodesModel::tr("Croatian")},
            QtvLangCode{"cus", LangCodesModel::tr("Cushitic (Other)")},
            QtvLangCode{"ces", LangCodesModel::tr("Czech")},
            QtvLangCode{"dak", LangCodesModel::tr("Dakota")},
            QtvLangCode{"dan", LangCodesModel::tr("Danish")},
            QtvLangCode{"dar", LangCodesModel::tr("Dargwa")},
            QtvLangCode{"day", LangCodesModel::tr("Dayak")},
            QtvLangCode{"del", LangCodesModel::tr("Delaware")},
            QtvLangCode{"chp", LangCodesModel::tr("Dene Suline")},
            QtvLangCode{"din", LangCodesModel::tr("Dinka")},
            QtvLangCode{"div", LangCodesModel::tr("Divehi; Dhivehi; Maldivian")},
            QtvLangCode{"doi", LangCodesModel::tr("Dogri")},
            QtvLangCode{"dgr", LangCodesModel::tr("Dogrib")},
            QtvLangCode{"dra", LangCodesModel::tr("Dravidian (Other)")},
            QtvLangCode{"dua", LangCodesModel::tr("Duala")},
            QtvLangCode{"nld", LangCodesModel::tr("Dutch; Flemish")},
            QtvLangCode{"dum", LangCodesModel::tr("Dutch, Middle (ca. 1050-1350)")},
            QtvLangCode{"dyu", LangCodesModel::tr("Dyula")},
            QtvLangCode{"dzo", LangCodesModel::tr("Dzongkha")},
            QtvLangCode{"efi", LangCodesModel::tr("Efik")},
            QtvLangCode{"egy", LangCodesModel::tr("Egyptian (Ancient)")},
            QtvLangCode{"eka", LangCodesModel::tr("Ekajuk")},
            QtvLangCode{"elx", LangCodesModel::tr("Elamite")},
            QtvLangCode{"eng", LangCodesModel::tr("English")},
            QtvLangCode{"enm", LangCodesModel::tr("English, Middle (ca. 1100-1500)")},
            QtvLangCode{"ang", LangCodesModel::tr("English, Old (ca. 450-1100)")},
            QtvLangCode{"myv", LangCodesModel::tr("Erzya")},
            QtvLangCode{"epo", LangCodesModel::tr("Esperanto")},
            QtvLangCode{"est", LangCodesModel::tr("Estonian")},
            QtvLangCode{"ewe", LangCodesModel::tr("Ewe")},
            QtvLangCode{"ewo", LangCodesModel::tr("Ewondo")},
            QtvLangCode{"fan", LangCodesModel::tr("Fang")},
            QtvLangCode{"fat", LangCodesModel::tr("Fanti")},
            QtvLangCode{"fao", LangCodesModel::tr("Faroese")},
            QtvLangCode{"fij", LangCodesModel::tr("Fijian")},
            QtvLangCode{"fil", LangCodesModel::tr("Filipino")},
            QtvLangCode{"fin", LangCodesModel::tr("Finnish")},
            QtvLangCode{"fiu", LangCodesModel::tr("Finno-Ugrian (Other)")},
            QtvLangCode{"fon", LangCodesModel::tr("Fon")},
            QtvLangCode{"fra", LangCodesModel::tr("French")},
            QtvLangCode{"frm", LangCodesModel::tr("French, Middle (ca. 1400-1600)")},
            QtvLangCode{"fro", LangCodesModel::tr("French, Old (842-ca. 1400)")},
            QtvLangCode{"frs", LangCodesModel::tr("Frisian, Eastern")},
            QtvLangCode{"frr", LangCodesModel::tr("Frisian, Northern")},
            QtvLangCode{"fry", LangCodesModel::tr("Frisian, Western")},
            QtvLangCode{"fur", LangCodesModel::tr("Friulian")},
            QtvLangCode{"ful", LangCodesModel::tr("Fulah")},
            QtvLangCode{"gaa", LangCodesModel::tr("Ga")},
            QtvLangCode{"glg", LangCodesModel::tr("Galician")},
            QtvLangCode{"lug", LangCodesModel::tr("Ganda")},
            QtvLangCode{"gay", LangCodesModel::tr("Gayo")},
            QtvLangCode{"gba", LangCodesModel::tr("Gbaya")},
            QtvLangCode{"gez", LangCodesModel::tr("Ge'ez")},
            QtvLangCode{"geo", LangCodesModel::tr("Georgian")},
            QtvLangCode{"kat", LangCodesModel::tr("Georgian")},
            QtvLangCode{"deu", LangCodesModel::tr("German")},
            QtvLangCode{"gsw", LangCodesModel::tr("German, Alemannic")},
            QtvLangCode{"nds", LangCodesModel::tr("German, Low; Low German; Saxon, Low; Low Saxon")},
            QtvLangCode{"gmh", LangCodesModel::tr("German, Middle High (ca. 1050-1500)")},
            QtvLangCode{"goh", LangCodesModel::tr("German, Old High (ca. 750-1050)")},
            QtvLangCode{"gem", LangCodesModel::tr("Germanic (Other)")},
            QtvLangCode{"gil", LangCodesModel::tr("Gilbertese; Kiribati")},
            QtvLangCode{"gon", LangCodesModel::tr("Gondi")},
            QtvLangCode{"gor", LangCodesModel::tr("Gorontalo")},
            QtvLangCode{"got", LangCodesModel::tr("Gothic")},
            QtvLangCode{"grb", LangCodesModel::tr("Grebo")},
            QtvLangCode{"grc", LangCodesModel::tr("Greek, Ancient (to 1453)")},
            QtvLangCode{"gre", LangCodesModel::tr("Greek, Modern (1453)")},
            QtvLangCode{"ell", LangCodesModel::tr("Greek, Modern (1453)")},
            QtvLangCode{"kal", LangCodesModel::tr("Greenlandic; Kalaallisut")},
            QtvLangCode{"grn", LangCodesModel::tr("Guarani")},
            QtvLangCode{"guj", LangCodesModel::tr("Gujarati")},
            QtvLangCode{"gwi", LangCodesModel::tr("Gwich'in")},
            QtvLangCode{"hai", LangCodesModel::tr("Haida")},
            QtvLangCode{"hat", LangCodesModel::tr("Haitian Creole; Haitian")},
            QtvLangCode{"hau", LangCodesModel::tr("Hausa")},
            QtvLangCode{"haw", LangCodesModel::tr("Hawaiian")},
            QtvLangCode{"heb", LangCodesModel::tr("Hebrew")},
            QtvLangCode{"her", LangCodesModel::tr("Herero")},
            QtvLangCode{"hil", LangCodesModel::tr("Hiligaynon")},
            QtvLangCode{"him", LangCodesModel::tr("Himachali")},
            QtvLangCode{"hin", LangCodesModel::tr("Hindi")},
            QtvLangCode{"hmo", LangCodesModel::tr("Hiri Motu")},
            QtvLangCode{"hit", LangCodesModel::tr("Hittite")},
            QtvLangCode{"hmn", LangCodesModel::tr("Hmong")},
            QtvLangCode{"hun", LangCodesModel::tr("Hungarian")},
            QtvLangCode{"hup", LangCodesModel::tr("Hupa")},
            QtvLangCode{"iba", LangCodesModel::tr("Iban")},
            QtvLangCode{"ice", LangCodesModel::tr("Icelandic")},
            QtvLangCode{"isl", LangCodesModel::tr("Icelandic")},
            QtvLangCode{"ido", LangCodesModel::tr("Ido")},
            QtvLangCode{"ibo", LangCodesModel::tr("Igbo")},
            QtvLangCode{"ijo", LangCodesModel::tr("Ijo")},
            QtvLangCode{"ilo", LangCodesModel::tr("Iloko")},
            QtvLangCode{"smn", LangCodesModel::tr("Inari Sami")},
            QtvLangCode{"inc", LangCodesModel::tr("Indic (Other)")},
            QtvLangCode{"ine", LangCodesModel::tr("Indo-European (Other)")},
            QtvLangCode{"ind", LangCodesModel::tr("Indonesian")},
            QtvLangCode{"inh", LangCodesModel::tr("Ingush")},
            QtvLangCode{"ina", LangCodesModel::tr("Interlingua (International Auxiliary Language Association)")},
            QtvLangCode{"ile", LangCodesModel::tr("Interlingue")},
            QtvLangCode{"iku", LangCodesModel::tr("Inuktitut")},
            QtvLangCode{"ipk", LangCodesModel::tr("Inupiaq")},
            QtvLangCode{"ira", LangCodesModel::tr("Iranian (Other)")},
            QtvLangCode{"gle", LangCodesModel::tr("Irish")},
            QtvLangCode{"mga", LangCodesModel::tr("Irish, Middle (900-1200)")},
            QtvLangCode{"sga", LangCodesModel::tr("Irish, Old (to 900)")},
            QtvLangCode{"iro", LangCodesModel::tr("Iroquoian languages")},
            QtvLangCode{"ita", LangCodesModel::tr("Italian")},
            QtvLangCode{"jpn", LangCodesModel::tr("Japanese")},
            QtvLangCode{"jav", LangCodesModel::tr("Javanese")},
            QtvLangCode{"jrb", LangCodesModel::tr("Judeo-Arabic")},
            QtvLangCode{"jpr", LangCodesModel::tr("Judeo-Persian")},
            QtvLangCode{"kbd", LangCodesModel::tr("Kabardian")},
            QtvLangCode{"kab", LangCodesModel::tr("Kabyle")},
            QtvLangCode{"kac", LangCodesModel::tr("Kachin")},
            QtvLangCode{"xal", LangCodesModel::tr("Kalmyk; Oirat")},
            QtvLangCode{"kam", LangCodesModel::tr("Kamba")},
            QtvLangCode{"kan", LangCodesModel::tr("Kannada")},
            QtvLangCode{"kau", LangCodesModel::tr("Kanuri")},
            QtvLangCode{"krc", LangCodesModel::tr("Karachay-Balkar")},
            QtvLangCode{"kaa", LangCodesModel::tr("Kara-Kalpak")},
            QtvLangCode{"krl", LangCodesModel::tr("Karelian")},
            QtvLangCode{"kar", LangCodesModel::tr("Karen")},
            QtvLangCode{"kas", LangCodesModel::tr("Kashmiri")},
            QtvLangCode{"csb", LangCodesModel::tr("Kashubian")},
            QtvLangCode{"kaw", LangCodesModel::tr("Kawi")},
            QtvLangCode{"kaz", LangCodesModel::tr("Kazakh")},
            QtvLangCode{"kha", LangCodesModel::tr("Khasi")},
            QtvLangCode{"khm", LangCodesModel::tr("Khmer")},
            QtvLangCode{"khi", LangCodesModel::tr("Khoisan (Other)")},
            QtvLangCode{"kho", LangCodesModel::tr("Khotanese")},
            QtvLangCode{"kik", LangCodesModel::tr("Kikuyu")},
            QtvLangCode{"kmb", LangCodesModel::tr("Kimbundu")},
            QtvLangCode{"kin", LangCodesModel::tr("Kinyarwanda")},
            QtvLangCode{"kir", LangCodesModel::tr("Kirghiz")},
            QtvLangCode{"tlh", LangCodesModel::tr("Klingon")},
            QtvLangCode{"kom", LangCodesModel::tr("Komi")},
            QtvLangCode{"kon", LangCodesModel::tr("Kongo")},
            QtvLangCode{"kok", LangCodesModel::tr("Konkani")},
            QtvLangCode{"kor", LangCodesModel::tr("Korean")},
            QtvLangCode{"kos", LangCodesModel::tr("Kosraean")},
            QtvLangCode{"kpe", LangCodesModel::tr("Kpelle")},
            QtvLangCode{"kro", LangCodesModel::tr("Kru")},
            QtvLangCode{"kua", LangCodesModel::tr("Kuanyama; Kwanyama")},
            QtvLangCode{"kum", LangCodesModel::tr("Kumyk")},
            QtvLangCode{"kur", LangCodesModel::tr("Kurdish")},
            QtvLangCode{"kru", LangCodesModel::tr("Kurukh")},
            QtvLangCode{"kut", LangCodesModel::tr("Kutenai")},
            QtvLangCode{"lad", LangCodesModel::tr("Ladino")},
            QtvLangCode{"lah", LangCodesModel::tr("Lahnda")},
            QtvLangCode{"lam", LangCodesModel::tr("Lamba")},
            QtvLangCode{"lao", LangCodesModel::tr("Lao")},
            QtvLangCode{"lat", LangCodesModel::tr("Latin")},
            QtvLangCode{"lav", LangCodesModel::tr("Latvian")},
            QtvLangCode{"lez", LangCodesModel::tr("Lezghian")},
            QtvLangCode{"lim", LangCodesModel::tr("Limburgish; Limburger; Limburgan")},
            QtvLangCode{"lin", LangCodesModel::tr("Lingala")},
            QtvLangCode{"lit", LangCodesModel::tr("Lithuanian")},
            QtvLangCode{"jbo", LangCodesModel::tr("Lojban")},
            QtvLangCode{"loz", LangCodesModel::tr("Lozi")},
            QtvLangCode{"lub", LangCodesModel::tr("Luba-Katanga")},
            QtvLangCode{"lua", LangCodesModel::tr("Luba-Lulua")},
            QtvLangCode{"lui", LangCodesModel::tr("Luise-o")},
            QtvLangCode{"smj", LangCodesModel::tr("Lule Sami")},
            QtvLangCode{"lun", LangCodesModel::tr("Lunda")},
            QtvLangCode{"luo", LangCodesModel::tr("Luo (Kenya and Tanzania)")},
            QtvLangCode{"lus", LangCodesModel::tr("Lushai")},
            QtvLangCode{"ltz", LangCodesModel::tr("Luxembourgish; Letzeburgesch")},
            QtvLangCode{"mac", LangCodesModel::tr("Macedonian")},
            QtvLangCode{"mkd", LangCodesModel::tr("Macedonian")},
            QtvLangCode{"mad", LangCodesModel::tr("Madurese")},
            QtvLangCode{"mag", LangCodesModel::tr("Magahi")},
            QtvLangCode{"mai", LangCodesModel::tr("Maithili")},
            QtvLangCode{"mak", LangCodesModel::tr("Makasar")},
            QtvLangCode{"mlg", LangCodesModel::tr("Malagasy")},
            QtvLangCode{"msa", LangCodesModel::tr("Malay")},
            QtvLangCode{"mal", LangCodesModel::tr("Malayalam")},
            QtvLangCode{"mlt", LangCodesModel::tr("Maltese")},
            QtvLangCode{"mnc", LangCodesModel::tr("Manchu")},
            QtvLangCode{"mdr", LangCodesModel::tr("Mandar")},
            QtvLangCode{"man", LangCodesModel::tr("Mandingo")},
            QtvLangCode{"mni", LangCodesModel::tr("Manipuri")},
            QtvLangCode{"mno", LangCodesModel::tr("Manobo languages")},
            QtvLangCode{"glv", LangCodesModel::tr("Manx")},
            QtvLangCode{"mao", LangCodesModel::tr("Maori")},
            QtvLangCode{"mri", LangCodesModel::tr("Maori")},
            QtvLangCode{"mar", LangCodesModel::tr("Marathi")},
            QtvLangCode{"chm", LangCodesModel::tr("Mari")},
            QtvLangCode{"mah", LangCodesModel::tr("Marshallese")},
            QtvLangCode{"mwr", LangCodesModel::tr("Marwari")},
            QtvLangCode{"mas", LangCodesModel::tr("Masai")},
            QtvLangCode{"myn", LangCodesModel::tr("Mayan languages")},
            QtvLangCode{"men", LangCodesModel::tr("Mende")},
            QtvLangCode{"mic", LangCodesModel::tr("Mi'kmaq; Micmac")},
            QtvLangCode{"min", LangCodesModel::tr("Minangkabau")},
            QtvLangCode{"mwl", LangCodesModel::tr("Mirandese")},
            QtvLangCode{"moh", LangCodesModel::tr("Mohawk")},
            QtvLangCode{"mdf", LangCodesModel::tr("Moksha")},
            QtvLangCode{"mol", LangCodesModel::tr("Moldavian")},
            QtvLangCode{"mkh", LangCodesModel::tr("Mon-Khmer (Other)")},
            QtvLangCode{"lol", LangCodesModel::tr("Mongo")},
            QtvLangCode{"mon", LangCodesModel::tr("Mongolian")},
            QtvLangCode{"mos", LangCodesModel::tr("Mossi")},
            QtvLangCode{"mun", LangCodesModel::tr("Munda languages")},
            QtvLangCode{"nah", LangCodesModel::tr("Nahuatl")},
            QtvLangCode{"nau", LangCodesModel::tr("Nauruan")},
            QtvLangCode{"nav", LangCodesModel::tr("Navajo; Navaho")},
            QtvLangCode{"nde", LangCodesModel::tr("Ndebele, North")},
            QtvLangCode{"nbl", LangCodesModel::tr("Ndebele, South")},
            QtvLangCode{"ndo", LangCodesModel::tr("Ndonga")},
            QtvLangCode{"nap", LangCodesModel::tr("Neapolitan")},
            QtvLangCode{"new", LangCodesModel::tr("Nepal Bhasa; Newari")},
            QtvLangCode{"nep", LangCodesModel::tr("Nepali")},
            QtvLangCode{"nia", LangCodesModel::tr("Nias")},
            QtvLangCode{"nic", LangCodesModel::tr("Niger-Kordofanian (Other)")},
            QtvLangCode{"ssa", LangCodesModel::tr("Nilo-Saharan (Other)")},
            QtvLangCode{"niu", LangCodesModel::tr("Niuean")},
            QtvLangCode{"nqo", LangCodesModel::tr("N'Ko")},
            QtvLangCode{"nog", LangCodesModel::tr("Nogai")},
            QtvLangCode{"non", LangCodesModel::tr("Norse, Old")},
            QtvLangCode{"nai", LangCodesModel::tr("North American Indian (Other)")},
            QtvLangCode{"sme", LangCodesModel::tr("Northern Sami")},
            QtvLangCode{"nor", LangCodesModel::tr("Norwegian")},
            QtvLangCode{"nob", LangCodesModel::tr("Norwegian Bokmål")},
            QtvLangCode{"nno", LangCodesModel::tr("Norwegian Nynorsk")},
            QtvLangCode{"nub", LangCodesModel::tr("Nubian languages")},
            QtvLangCode{"nym", LangCodesModel::tr("Nyamwezi")},
            QtvLangCode{"nyn", LangCodesModel::tr("Nyankole")},
            QtvLangCode{"nyo", LangCodesModel::tr("Nyoro")},
            QtvLangCode{"nzi", LangCodesModel::tr("Nzima")},
            QtvLangCode{"oci", LangCodesModel::tr("Occitan (post 1500); Provençal")},
            QtvLangCode{"oji", LangCodesModel::tr("Ojibwa, Anishinaabe languages")},
            QtvLangCode{"ori", LangCodesModel::tr("Oriya")},
            QtvLangCode{"orm", LangCodesModel::tr("Oromo")},
            QtvLangCode{"osa", LangCodesModel::tr("Osage")},
            QtvLangCode{"oss", LangCodesModel::tr("Ossetian; Ossetic")},
            QtvLangCode{"oto", LangCodesModel::tr("Otomian languages")},
            QtvLangCode{"pal", LangCodesModel::tr("Pahlavi (Middle Persian)")},
            QtvLangCode{"pau", LangCodesModel::tr("Palauan")},
            QtvLangCode{"pli", LangCodesModel::tr("Pali")},
            QtvLangCode{"pam", LangCodesModel::tr("Pampanga")},
            QtvLangCode{"pag", LangCodesModel::tr("Pangasinan")},
            QtvLangCode{"pap", LangCodesModel::tr("Papiamento")},
            QtvLangCode{"paa", LangCodesModel::tr("Papuan (Other)")},
            QtvLangCode{"fas", LangCodesModel::tr("Persian")},
            QtvLangCode{"peo", LangCodesModel::tr("Persian, Old (ca. 600-400 BC)")},
            QtvLangCode{"phi", LangCodesModel::tr("Philippine (Other)")},
            QtvLangCode{"phn", LangCodesModel::tr("Phoenician")},
            QtvLangCode{"pon", LangCodesModel::tr("Pohnpeian")},
            QtvLangCode{"pol", LangCodesModel::tr("Polish")},
            QtvLangCode{"por", LangCodesModel::tr("Portuguese")},
            QtvLangCode{"pra", LangCodesModel::tr("Prakrit languages")},
            QtvLangCode{"pro", LangCodesModel::tr("Provençal, Old (to 1500)")},
            QtvLangCode{"pan", LangCodesModel::tr("Punjabi; Panjabi")},
            QtvLangCode{"pus", LangCodesModel::tr("Pushto")},
            QtvLangCode{"que", LangCodesModel::tr("Quechuan languages")},
            QtvLangCode{"roh", LangCodesModel::tr("Raeto-Romance")},
            QtvLangCode{"raj", LangCodesModel::tr("Rajasthani")},
            QtvLangCode{"rap", LangCodesModel::tr("Rapanui")},
            QtvLangCode{"rar", LangCodesModel::tr("Rarotongan")},
            QtvLangCode{"roa", LangCodesModel::tr("Romance (Other)")},
            QtvLangCode{"rum", LangCodesModel::tr("Romanian")},
            QtvLangCode{"ron", LangCodesModel::tr("Romanian")},
            QtvLangCode{"rom", LangCodesModel::tr("Romany")},
            QtvLangCode{"run", LangCodesModel::tr("Rundi")},
            QtvLangCode{"rus", LangCodesModel::tr("Russian")},
            QtvLangCode{"sal", LangCodesModel::tr("Salishan languages")},
            QtvLangCode{"sam", LangCodesModel::tr("Samaritan Aramaic")},
            QtvLangCode{"smi", LangCodesModel::tr("Sami languages (Other)")},
            QtvLangCode{"smo", LangCodesModel::tr("Samoan")},
            QtvLangCode{"sad", LangCodesModel::tr("Sandawe")},
            QtvLangCode{"sag", LangCodesModel::tr("Sango")},
            QtvLangCode{"san", LangCodesModel::tr("Sanskrit")},
            QtvLangCode{"sat", LangCodesModel::tr("Santali")},
            QtvLangCode{"srd", LangCodesModel::tr("Sardinian")},
            QtvLangCode{"sas", LangCodesModel::tr("Sasak")},
            QtvLangCode{"sco", LangCodesModel::tr("Scots")},
            QtvLangCode{"gla", LangCodesModel::tr("Scottish Gaelic; Gaelic")},
            QtvLangCode{"sel", LangCodesModel::tr("Selkup")},
            QtvLangCode{"sem", LangCodesModel::tr("Semitic (Other)")},
            QtvLangCode{"srp", LangCodesModel::tr("Serbian")},
            QtvLangCode{"srr", LangCodesModel::tr("Serer")},
            QtvLangCode{"shn", LangCodesModel::tr("Shan")},
            QtvLangCode{"sna", LangCodesModel::tr("Shona")},
            QtvLangCode{"iii", LangCodesModel::tr("Sichuan Yi")},
            QtvLangCode{"scn", LangCodesModel::tr("Sicilian")},
            QtvLangCode{"sid", LangCodesModel::tr("Sidamo")},
            QtvLangCode{"sgn", LangCodesModel::tr("Sign languages")},
            QtvLangCode{"bla", LangCodesModel::tr("Siksika")},
            QtvLangCode{"snd", LangCodesModel::tr("Sindhi")},
            QtvLangCode{"sin", LangCodesModel::tr("Sinhalese; Sinhala")},
            QtvLangCode{"sit", LangCodesModel::tr("Sino-Tibetan (Other)")},
            QtvLangCode{"sio", LangCodesModel::tr("Siouan languages")},
            QtvLangCode{"sms", LangCodesModel::tr("Skolt Sami")},
            QtvLangCode{"den", LangCodesModel::tr("Slave (Athapascan)")},
            QtvLangCode{"sla", LangCodesModel::tr("Slavic (Other)")},
            QtvLangCode{"slk", LangCodesModel::tr("Slovak")},
            QtvLangCode{"slv", LangCodesModel::tr("Slovenian")},
            QtvLangCode{"sog", LangCodesModel::tr("Sogdian")},
            QtvLangCode{"som", LangCodesModel::tr("Somali")},
            QtvLangCode{"son", LangCodesModel::tr("Songhai")},
            QtvLangCode{"snk", LangCodesModel::tr("Soninke")},
            QtvLangCode{"wen", LangCodesModel::tr("Sorbian languages")},
            QtvLangCode{"dsb", LangCodesModel::tr("Sorbian, Lower")},
            QtvLangCode{"hsb", LangCodesModel::tr("Sorbian, Upper")},
            QtvLangCode{"nso", LangCodesModel::tr("Sotho; Northern; Pedi; Sepedi")},
            QtvLangCode{"sot", LangCodesModel::tr("Sotho, Southern")},
            QtvLangCode{"sai", LangCodesModel::tr("South American Indian (Other)")},
            QtvLangCode{"alt", LangCodesModel::tr("Southern Altai")},
            QtvLangCode{"sma", LangCodesModel::tr("Southern Sami")},
            QtvLangCode{"spa", LangCodesModel::tr("Spanish; Castilian")},
            QtvLangCode{"srn", LangCodesModel::tr("Sranan Tongo")},
            QtvLangCode{"suk", LangCodesModel::tr("Sukuma")},
            QtvLangCode{"sux", LangCodesModel::tr("Sumerian")},
            QtvLangCode{"sun", LangCodesModel::tr("Sundanese")},
            QtvLangCode{"sus", LangCodesModel::tr("Susu")},
            QtvLangCode{"swa", LangCodesModel::tr("Swahili")},
            QtvLangCode{"ssw", LangCodesModel::tr("Swati")},
            QtvLangCode{"swe", LangCodesModel::tr("Swedish")},
            QtvLangCode{"syr", LangCodesModel::tr("Syriac")},
            QtvLangCode{"tgl", LangCodesModel::tr("Tagalog")},
            QtvLangCode{"tah", LangCodesModel::tr("Tahitian")},
            QtvLangCode{"tai", LangCodesModel::tr("Tai (Other)")},
            QtvLangCode{"tgk", LangCodesModel::tr("Tajik")},
            QtvLangCode{"tmh", LangCodesModel::tr("Tamashek")},
            QtvLangCode{"tam", LangCodesModel::tr("Tamil")},
            QtvLangCode{"tat", LangCodesModel::tr("Tatar")},
            QtvLangCode{"tel", LangCodesModel::tr("Telugu")},
            QtvLangCode{"ter", LangCodesModel::tr("Tereno")},
            QtvLangCode{"tet", LangCodesModel::tr("Tetum, Lia-Tetun")},
            QtvLangCode{"tha", LangCodesModel::tr("Thai")},
            QtvLangCode{"tib", LangCodesModel::tr("Tibetan")},
            QtvLangCode{"bod", LangCodesModel::tr("Tibetan")},
            QtvLangCode{"tig", LangCodesModel::tr("Tigre")},
            QtvLangCode{"tir", LangCodesModel::tr("Tigrinya")},
            QtvLangCode{"tem", LangCodesModel::tr("Timne")},
            QtvLangCode{"tiv", LangCodesModel::tr("Tiv")},
            QtvLangCode{"tli", LangCodesModel::tr("Tlingit")},
            QtvLangCode{"tpi", LangCodesModel::tr("Tok Pisin")},
            QtvLangCode{"tkl", LangCodesModel::tr("Tokelau")},
            QtvLangCode{"tog", LangCodesModel::tr("Tonga (Malawi)")},
            QtvLangCode{"ton", LangCodesModel::tr("Tongan")},
            QtvLangCode{"tsi", LangCodesModel::tr("Tsimshian")},
            QtvLangCode{"tso", LangCodesModel::tr("Tsonga")},
            QtvLangCode{"tsn", LangCodesModel::tr("Tswana")},
            QtvLangCode{"tum", LangCodesModel::tr("Tumbuka")},
            QtvLangCode{"tup", LangCodesModel::tr("Tupi languages")},
            QtvLangCode{"tur", LangCodesModel::tr("Turkish")},
            QtvLangCode{"ota", LangCodesModel::tr("Turkish, Ottoman (1500-1928)")},
            QtvLangCode{"tuk", LangCodesModel::tr("Turkmen")},
            QtvLangCode{"tvl", LangCodesModel::tr("Tuvalu")},
            QtvLangCode{"tyv", LangCodesModel::tr("Tuvinian")},
            QtvLangCode{"twi", LangCodesModel::tr("Twi")},
            QtvLangCode{"udm", LangCodesModel::tr("Udmurt")},
            QtvLangCode{"uga", LangCodesModel::tr("Ugaritic")},
            QtvLangCode{"uig", LangCodesModel::tr("Uighur; Uyghur")},
            QtvLangCode{"ukr", LangCodesModel::tr("Ukrainian")},
            QtvLangCode{"umb", LangCodesModel::tr("Umbundu")},
            QtvLangCode{"urd", LangCodesModel::tr("Urdu")},
            QtvLangCode{"uzb", LangCodesModel::tr("Uzbek")},
            QtvLangCode{"vai", LangCodesModel::tr("Vai")},
            QtvLangCode{"ven", LangCodesModel::tr("Venda")},
            QtvLangCode{"vie", LangCodesModel::tr("Vietnamese")},
            QtvLangCode{"vol", LangCodesModel::tr("Volapük")},
            QtvLangCode{"vot", LangCodesModel::tr("Votic")},
            QtvLangCode{"wak", LangCodesModel::tr("Wakashan languages")},
            QtvLangCode{"wal", LangCodesModel::tr("Walamo")},
            QtvLangCode{"wln", LangCodesModel::tr("Walloon")},
            QtvLangCode{"war", LangCodesModel::tr("Waray")},
            QtvLangCode{"was", LangCodesModel::tr("Washo")},
            QtvLangCode{"wel", LangCodesModel::tr("Welsh")},
            QtvLangCode{"cym", LangCodesModel::tr("Welsh")},
            QtvLangCode{"wol", LangCodesModel::tr("Wolof")},
            QtvLangCode{"xho", LangCodesModel::tr("Xhosa")},
            QtvLangCode{"sah", LangCodesModel::tr("Yakut")},
            QtvLangCode{"yao", LangCodesModel::tr("Yao")},
            QtvLangCode{"yap", LangCodesModel::tr("Yapese")},
            QtvLangCode{"yid", LangCodesModel::tr("Yiddish")},
            QtvLangCode{"yor", LangCodesModel::tr("Yoruba")},
            QtvLangCode{"ypk", LangCodesModel::tr("Yupik languages")},
            QtvLangCode{"znd", LangCodesModel::tr("Zande")},
            QtvLangCode{"zza", LangCodesModel::tr("Zaza; Dimili; Dimli; Kirdki; Kirmanjki; Zazaki")},
            QtvLangCode{"zap", LangCodesModel::tr("Zapotec")},
            QtvLangCode{"zen", LangCodesModel::tr("Zenaga")},
            QtvLangCode{"zha", LangCodesModel::tr("Zhuang; Chuang")},
            QtvLangCode{"zul", LangCodesModel::tr("Zulu")},
            QtvLangCode{"zun", LangCodesModel::tr("Zuni'")}};
}
