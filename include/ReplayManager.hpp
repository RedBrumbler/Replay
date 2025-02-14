#pragma once

#include "Utils.hpp"

#include "GlobalNamespace/IDifficultyBeatmap.hpp"
#include "GlobalNamespace/NoteController.hpp"
#include "GlobalNamespace/ObstacleController.hpp"
// #include "GlobalNamespace/BloomPrePassGraphicsSettingsPresetsSO_Preset.hpp"
// #include "GlobalNamespace/BloomPrePassEffectContainerSO.hpp"
#include "GlobalNamespace/MirrorRendererGraphicsSettingsPresets_Preset.hpp"
#include "GlobalNamespace/MirrorRendererSO.hpp"

struct ScoreFrame;
struct NoteEvent;
struct WallEvent;
struct HeightEvent;
struct PauseEvent;

namespace Manager {

    namespace Camera {
        extern bool rendering;

        // extern GlobalNamespace::BloomPrePassGraphicsSettingsPresetsSO* bloomPresets;
        // extern GlobalNamespace::BloomPrePassEffectContainerSO* bloomContainer;
        extern GlobalNamespace::MirrorRendererGraphicsSettingsPresets* mirrorPresets;
        extern GlobalNamespace::MirrorRendererSO* mirrorRenderer;

        Vector3 GetHeadPosition();
        Quaternion GetHeadRotation();
        int GetMode();
    }
    
    namespace Frames {
        ScoreFrame* GetScoreFrame();
        bool AllowComboDrop();
    }
    
    namespace Events {
        extern float wallEnergyLoss;
        void AddNoteController(GlobalNamespace::NoteController* note);
        void RemoveNoteController(GlobalNamespace::NoteController* note);
    }

    void SetLevel(GlobalNamespace::IDifficultyBeatmap* level);
    
    void SetReplays(std::unordered_map<std::string, ReplayWrapper> replays, bool external = false);
    void RefreshLevelReplays();
    bool AreReplaysLocal();
    
    void ReplayStarted(ReplayWrapper& wrapper);
    void ReplayStarted(const std::string& path);
    void ReplayRestarted(bool full = true);
    void EndSceneChangeStarted();
    void ReplayEnded();
    void ReplayPaused();
    void ReplayUnpaused();

    extern bool replaying;
    extern bool paused;
    extern ReplayWrapper currentReplay;
    extern GlobalNamespace::IDifficultyBeatmap* beatmap;

    const ReplayInfo& GetCurrentInfo();

    void UpdateTime(float songTime);
    float GetSongTime();
    const Frame& GetFrame();
    const Frame& GetNextFrame();
    float GetFrameProgress();
}
