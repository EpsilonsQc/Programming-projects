using UnityEngine; 

[CreateAssetMenu(fileName = "NewFireworks", menuName = "Data/Fireworks/FireworksData")]

public class FireworksData : ScriptableObject
{
    [Header("Variables")]
    public float speedMin = 0.5f;
    public float speedMax = 1f;
    public float sizeMin = 0.1f;
    public float sizeMax = 0.5f;
    public int nbParticles = 20;
    public float lifeTime = 1f;
    public float sizeGrowth = 0.1f;

    [Header("Colors")]
    public Color startColor = default;
    public Color endColor = default;

    [Header("GameObjects")]
    public GameObject Prefab;

    [Header("String")]
    private string FireWorksName = default;

    public void Setup(string newName)
    {
        FireWorksName = newName;
    }
}
