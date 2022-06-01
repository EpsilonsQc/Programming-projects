using System.Collections; 
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using TMPro;

public class LoadScene : MonoBehaviour
{
    [Header("GAME OBJECTS")]
    [SerializeField] Button loadGameButton;
    [SerializeField] Image textLoadingPercentageImg;
    [SerializeField] Image loadingBarImg;
    [SerializeField] Image loadingBarProgressImg;
    [SerializeField] TextMeshProUGUI loadGameButtonText;
    [SerializeField] TextMeshProUGUI loadingPercentageText;
    [Space(15)]

    [Header("BOOLEAN PARAMETERS")]
    [SerializeField] bool startLoadingScene = false;
    [SerializeField] bool sceneIsLoaded = false;
    [SerializeField] bool enterScene = false;
    [Space(15)]

    [Header("VARIABLES")]
    [SerializeField] float textLoadingProgress = 0f;
    [SerializeField] float changePerSecond = 10f;

    // Awake
    void Awake()
    {
        loadGameButton = GameObject.Find("Canvas/Load Game (Button)").GetComponent<Button>();
        loadGameButton.onClick.AddListener(StartLoadingScene);
        loadGameButton.onClick.AddListener(EnterTheScene);

        textLoadingPercentageImg = GameObject.Find("Canvas/Loading Percentage (Image)").GetComponent<Image>();
        loadingBarImg = GameObject.Find("Canvas/Loading Bar (Image)").GetComponent<Image>();
        loadingBarProgressImg = GameObject.Find("Canvas/Loading Bar (Image)/Loading Bar Progress (Image)").GetComponent<Image>();

        loadGameButtonText = GameObject.Find("Canvas/Load Game (Button)/Load Game (Text)").GetComponent<TextMeshProUGUI>();
        loadingPercentageText = GameObject.Find("Canvas/Loading Percentage (Image)/Loading Percentage (Text)").GetComponent<TextMeshProUGUI>();
    }

    // Update is called once per frame
    void Update()
    {
        if (startLoadingScene == true && textLoadingProgress <= 100)
        {
            textLoadingPercentageImg.enabled = true;
            loadingBarImg.enabled = true;
            loadingBarProgressImg.enabled = true;

            textLoadingProgress += changePerSecond * Time.deltaTime;
            loadingPercentageText.text = ((int)textLoadingProgress + "%");

            loadingBarProgressImg.fillAmount = (float)textLoadingProgress / 100f;
        }
    }

    // Start loading scene
    public void StartLoadingScene()
    {
        StartCoroutine(LoadMyScene());
    }

    // Load my scene (coroutine)
    IEnumerator LoadMyScene()
    {
        if (startLoadingScene == false)
        {
            AsyncOperation asyncLoad = SceneManager.LoadSceneAsync("InGameScene");
            asyncLoad.allowSceneActivation = false;
        
            while (asyncLoad.isDone == false)
            {
                startLoadingScene = true;

                if(textLoadingProgress >= 100)
                {
                    loadGameButtonText.text = "Start";
                    sceneIsLoaded = true;
                    loadGameButton.onClick.RemoveListener(StartLoadingScene);

                    if(enterScene == true)
                    {
                        asyncLoad.allowSceneActivation = true;
                        loadGameButton.onClick.RemoveListener(EnterTheScene);
                    }
                }
                yield return null; // wait until the next frame before continuing
            }
        }
    }

    // Enter the scene
    public void EnterTheScene()
    {
        if(sceneIsLoaded == true)
        {
            enterScene = true;
        }
    }
}