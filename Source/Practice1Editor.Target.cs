// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Practice1EditorTarget : TargetRules
{
	public Practice1EditorTarget( TargetInfo Target) : base(Target)
	{
        bShowIncludes = true;

        Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
		ExtraModuleNames.Add("Practice1");
	}
}
