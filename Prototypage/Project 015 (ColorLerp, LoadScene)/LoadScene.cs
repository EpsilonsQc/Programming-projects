using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class LoadScene : MonoBehaviour
{
    [SerializeField] bool go = false;
    private Button loadingButton;
    private int counter;

    void Start()
    {
        loadingButton = GameObject.Find("Canvas/Load Scene with Listeners (Button)").GetComponent<Button>();
        loadingButton.onClick.AddListener(StartLoadingTheScene);
        loadingButton.onClick.AddListener(ListenerTest);
    }

    public void ListenerTest()
    {
        counter++;
        Debug.Log("Counter: " + counter);

        if(counter >= 10)
        {
            // loadingButton.onClick.RemoveAllListeners();
            // Debug.Log("Remove All Listeners: OK");
            loadingButton.onClick.RemoveListener(StartLoadingTheScene);
            Debug.Log("Remove Listeners: OK");
        }
    }

    public void StartLoadingTheScene()
    {
        Debug.Log("Start Coroutine: OK");
        StartCoroutine(LoadYourAsyncScene());
        // loadingButton.onClick.RemoveAllListeners();
        // Debug.Log("RemoveAllListeners: OK");
    }

    IEnumerator LoadYourAsyncScene()
    {
        AsyncOperation asyncLoad = SceneManager.LoadSceneAsync("SceneToLoad");
        asyncLoad.allowSceneActivation = false; // Afin d'éviter que la scène ce charge directement

        while (!asyncLoad.isDone)
        {
            float progress = asyncLoad.progress * 100;
            Debug.Log(progress + " %");

            if(asyncLoad.progress >= 0.90f)
            {
                if(go == true)asyncLoad.allowSceneActivation = true;
            }

            yield return null; // Continuer au prochain frame
        }
    }
}