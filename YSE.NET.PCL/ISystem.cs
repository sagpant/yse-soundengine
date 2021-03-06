﻿using System;
using System.Collections.Generic;
using System.Text;

namespace IYse
{
  public interface ISystem
  {
    bool Init();
    void Update();
    void Close();

    void Pause();
    void Resume();
    void AutoReconnect(bool on, int delay);
    int MissedCallbacks();

    //IReverb GlobalReverb { get; }

    uint NumDevices { get; }
    IDevice GetDevice(uint nr);

		void OpenDevice(IDeviceSetup setup, ChannelType channeltype);
		void CloseCurrentDevice();
		string DefaultDevice { get; }
		string DefaultHost { get; }

    int MaxSounds { get; set; }

    bool AudioTest { get; set; }

    float CpuLoad { get; }

		string Version { get; }

    IReverb GetReverb();
  }
}
