/**
 * config.cpp
 * 
 * Configuration file handling for button positions.
 * Saves/loads positions to a simple text config file.
 * 
 * Author: OgMorrow2090
 * Repository: https://github.com/OgMorrow2090/guildwars2
 */

#include "shared.h"
#include <fstream>
#include <string>
#include <cstdio>

// =============================================================================
// Button Position State
// =============================================================================

// Default positions - will be overwritten by config or capture
int g_DepositX = 0;
int g_DepositY = 0;
int g_SortX = 0;
int g_SortY = 0;
int g_ChestX = 0;
int g_ChestY = 0;

// Config file path
static std::string g_ConfigPath;

// =============================================================================
// Config File Functions
// =============================================================================

void SetConfigPath(const char* addonPath)
{
    if (addonPath != nullptr)
    {
        g_ConfigPath = std::string(addonPath) + "\\inventory-hotkeys.cfg";
        
        // Create directory if it doesn't exist
        CreateDirectoryA(addonPath, NULL);
    }
}

void LoadButtonPositions()
{
    if (g_ConfigPath.empty())
    {
        APIDefs->Log(LOGL_WARNING, "InventoryHotkeys", "Config path not set");
        return;
    }
    
    std::ifstream file(g_ConfigPath);
    if (!file.is_open())
    {
        APIDefs->Log(LOGL_INFO, "InventoryHotkeys", "No config file - use Ctrl+Shift+D/C/B to capture positions");
        return;
    }
    
    std::string line;
    while (std::getline(file, line))
    {
        if (line.find("DepositX=") == 0)
            g_DepositX = std::stoi(line.substr(9));
        else if (line.find("DepositY=") == 0)
            g_DepositY = std::stoi(line.substr(9));
        else if (line.find("SortX=") == 0)
            g_SortX = std::stoi(line.substr(6));
        else if (line.find("SortY=") == 0)
            g_SortY = std::stoi(line.substr(6));
        else if (line.find("ChestX=") == 0)
            g_ChestX = std::stoi(line.substr(7));
        else if (line.find("ChestY=") == 0)
            g_ChestY = std::stoi(line.substr(7));
    }
    
    file.close();
    
    char buffer[256];
    sprintf_s(buffer, "Loaded: Deposit(%d,%d) Sort(%d,%d) Chest(%d,%d)", 
              g_DepositX, g_DepositY, g_SortX, g_SortY, g_ChestX, g_ChestY);
    APIDefs->Log(LOGL_INFO, "InventoryHotkeys", buffer);
}

void SaveButtonPositions()
{
    if (g_ConfigPath.empty())
    {
        APIDefs->Log(LOGL_WARNING, "InventoryHotkeys", "Config path not set");
        APIDefs->GUI_SendAlert("Error: Config path not set!");
        return;
    }
    
    std::ofstream file(g_ConfigPath);
    if (!file.is_open())
    {
        APIDefs->Log(LOGL_WARNING, "InventoryHotkeys", "Failed to save config file");
        APIDefs->GUI_SendAlert("Error: Could not save config file!");
        return;
    }
    
    file << "DepositX=" << g_DepositX << "\n";
    file << "DepositY=" << g_DepositY << "\n";
    file << "SortX=" << g_SortX << "\n";
    file << "SortY=" << g_SortY << "\n";
    file << "ChestX=" << g_ChestX << "\n";
    file << "ChestY=" << g_ChestY << "\n";
    
    file.close();
    
    APIDefs->Log(LOGL_INFO, "InventoryHotkeys", "Positions saved to config file");
}
