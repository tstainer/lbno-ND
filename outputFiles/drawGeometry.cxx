{
  gSystem->Load("libGeom");
  TGeoManager::Import("ND_geometry.root");
  TGeoVolume * Rock_Volume = gGeoManager->GetVolume("Rock_Volume");
  TGeoVolume * Cavity_Volume = gGeoManager->GetVolume("Cavity_MIND_Volume");
  gGeoManager->SetTopVisible(kFALSE);
  gGeoManager->SetVisOption(0);
  gGeoManager->SetVisLevel(10);
  gGeoManager->GetMasterVolume()->Draw();
  //Cavity_Volume->Draw();

  //loop through the volumes in the ECAL
  
  Int_t ECAL_Count = 0;  
  Int_t HCAL_Count = 0;

  for(Int_t i=0;i<gGeoManager->GetListOfVolumes()->GetEntries()-1;i++)
    {
      std::string VolumeName = gGeoManager->GetListOfVolumes()->At(i)->GetName();
      std::string NextVolumeName = gGeoManager->GetListOfVolumes()->At(i+1)->GetName();

      if(VolumeName == "ECALScintillator_Volume")// && NextVolumeName != "ECALScintillator_Volume" )
	{
	  ECAL_Count++;
	}

      if(VolumeName == "HCALScintillator_Volume")// && NextVolumeName != "HCALScintillator_Volume")
	{
	  HCAL_Count++;
	}
    }

  //not sure how it counts but it works if you discount 3 and divide by 6 not 5!
  std::cout << "\nThe number of ECAL layers is: " << (Double_t)(ECAL_Count-3)/6.0;
  std::cout << "\nThe number of HCAL layers is: " << (Double_t)(HCAL_Count-3)/6.0 <<std::endl;

}
