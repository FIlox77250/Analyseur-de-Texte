#include <windows.h>
#include <string>
#include <sstream>
#include <vector>

// Identifiants des contrôles
#define ID_EDIT 1
#define ID_ANALYZE_BUTTON 2
#define ID_RESULT 3

// Variables globales
HWND hEdit, hResult, hButton;
HINSTANCE hInst;

class TextAnalyzer {
private:
    std::string text;

public:
    TextAnalyzer(const std::string& input) : text(input) {}

    int countCharacters() const {
        return text.length();
    }

    int countCharactersNoSpaces() const {
        int count = 0;
        for (char c : text) {
            if (c != ' ' && c != '\n' && c != '\r' && c != '\t') count++;
        }
        return count;
    }

    int countWords() const {
        std::istringstream iss(text);
        std::string word;
        int count = 0;
        while (iss >> word) count++;
        return count;
    }

    int countSentences() const {
        int count = 0;
        for (size_t i = 0; i < text.length(); i++) {
            if (text[i] == '.' || text[i] == '!' || text[i] == '?') count++;
        }
        return count > 0 ? count : 1;
    }
};

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            // Zone de texte d'entrée
            hEdit = CreateWindowW(
                    L"EDIT", L"",
                    WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_VSCROLL | WS_BORDER,
                    10, 10, 460, 150, hwnd, (HMENU)ID_EDIT,
                    hInst, NULL);

            // Bouton Analyser
            hButton = CreateWindowW(
                    L"BUTTON", L"Analyser",
                    WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                    190, 170, 100, 30, hwnd, (HMENU)ID_ANALYZE_BUTTON,
                    hInst, NULL);

            // Zone de résultats
            hResult = CreateWindowW(
                    L"EDIT", L"",
                    WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_READONLY | WS_BORDER,
                    10, 210, 460, 100, hwnd, (HMENU)ID_RESULT,
                    hInst, NULL);

            return 0;
        }

        case WM_COMMAND: {
            if (LOWORD(wParam) == ID_ANALYZE_BUTTON) {
                int len = GetWindowTextLengthW(hEdit);
                if (len > 0) {
                    std::vector<wchar_t> buffer(len + 1);
                    GetWindowTextW(hEdit, buffer.data(), len + 1);

                    // Convertir wchar_t en string pour l'analyse
                    std::string text(len, 0);
                    WideCharToMultiByte(CP_UTF8, 0, buffer.data(), -1, &text[0], len, NULL, NULL);

                    // Analyse
                    TextAnalyzer analyzer(text);

                    // Préparation des résultats
                    std::wstringstream results;
                    results << L"Caracteres total: " << analyzer.countCharacters() << L"\r\n";
                    results << L"Caracteres (sans espaces): " << analyzer.countCharactersNoSpaces() << L"\r\n";
                    results << L"Nombre de mots: " << analyzer.countWords() << L"\r\n";
                    results << L"Nombre de phrases: " << analyzer.countSentences() << L"\r\n";

                    // Affichage des résultats
                    SetWindowTextW(hResult, results.str().c_str());
                }
            }
            return 0;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    hInst = hInstance;

    // Enregistrement de la classe de fenêtre
    WNDCLASSEXW wc = {0};
    wc.cbSize = sizeof(WNDCLASSEXW);
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"TextAnalyzerClass";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    if (!RegisterClassExW(&wc)) {
        return 0;
    }

    // Création de la fenêtre principale
    HWND hwnd = CreateWindowW(
            L"TextAnalyzerClass", L"Analyseur de Texte",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, 500, 370,
            NULL, NULL, hInstance, NULL
    );

    if (!hwnd) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Boucle de messages
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}