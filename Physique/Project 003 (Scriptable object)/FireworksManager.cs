using System.Collections.Generic;
using UnityEngine;

public class FireworksManager : MonoBehaviour
{
    public List<FireworksData> fireworkList = new List<FireworksData>();

    private void Update()
    {
        if(Input.GetKeyDown(KeyCode.Space))
        {
            InstanciateFireworks();
            fireworkList[0].nbParticles += 1;
        }
    }

    private void InstanciateFireworks()
    {
        int rand = UnityEngine.Random.Range(0, fireworkList.Count);

        GameObject GO = Instantiate(fireworkList[rand].Prefab);
    }
}