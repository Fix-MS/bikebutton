// INFO: use the following list to modify the requests
// https://github.com/Fix-MS/backend#flaw-type-list

// Geh-/Radweg, Radverkehr - starke Verschmutzung/Scherben (83)
const char* jsonSendData1 = "{ " \
  "\"type\": 83, " \
  "\"location\": \"Schlossplatz, Promenade\", "\
  "\"firstname\": \"Vortragender\", "\
  "\"lastname\": \"Mustermann\", "\
  "\"email\": \"fixms@example.com\" "\
  "}";

// Beleuchtung - Leuchte an Straße, Geh- oder Radweg defekt (75)
const char* jsonSendData2 = "{ " \
  "\"type\": 75, " \
  "\"location\": \"Hafenplatz 1\", "\
  "\"firstname\": \ "Vortragender\", "\
  "\"lastname\": \"Mustermann\", "\
  "\"email\": \"fixms@example.com\" "\
  "}";

// Straße - Schlagloch (92)
const char* jsonSendData3 = "{ " \
  "\"type\": 92, " \
  "\"location\": \"here\", "\
  "\"firstname\": \"Vortragender\", "\
  "\"lastname\": \"Mustermann\", "\
  "\"email\": \"fixms@example.com\" "\
  "}";
